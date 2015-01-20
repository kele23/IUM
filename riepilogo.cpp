#include "riepilogo.h"
#include "ui_riepilogo.h"

Riepilogo::Riepilogo(QWidget *parent,QList<Result> *res) :
    QWidget(parent),
    ui(new Ui::Riepilogo)
{
    ui->setupUi(this);

    this->res = new QList<Result>();
    loadResults();

    QString insert = "";
    for(int i = 0; i < res->size(); i++){
        Result r = res->at(i);
        this->res->append(r);
        insert +="<P><STRONG>"+r.name+"</STRONG>: "+QString::number(r.value)+"</P>";
    }

    QMap<QString,int> avg;
    QMap<QString,int> count;
    for(int i = 0; i < this->res->size(); i++){
        Result r = this->res->at(i);
        avg.insert(r.name,avg.remove(r.name)+r.value);
        count.insert(r.name,count.remove(r.name)+1);
    }

    QString avgS = "";
    foreach( QString key, avg.keys() ){
        int value = avg.value(key) / count.value(key) ;
        avgS +="<P><STRONG>"+key+"</STRONG>: "+QString::number(value)+"</P>";
    }

    ui->riepilogoText->setText("<HTML><HEAD></HEAD>"
                               "    <BODY> "
                               "        <H3 align=\"center\"> Punteggio Finale </H3> "
                               "        "+insert+" "
                               "        <P></P>"
                               "        <H3 align=\"center\"> Media Risultati </H3> "
                               "        "+avgS+" "
                               "        <P align=\"right\"> Minore è meglio </P>"
                               "    </BODY></HTML>");

    saveResults();

}

Riepilogo::~Riepilogo()
{
    delete ui;
}

void Riepilogo::saveResults(){
    QFile file("results.xml");
    file.open(QIODevice::ReadWrite);

    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();

    stream.writeStartElement("RESULTS");

    for(int i = 0; i < res->size(); i++){
        Result r = res->at(i);
        stream.writeStartElement("TEST");
            //stream.writeAttribute("datetime", "http://qt.nokia.com/");
            stream.writeTextElement("NAME",r.name);
            stream.writeTextElement("VALUE",QString::number(r.value));
        stream.writeEndElement();
    }

    stream.writeEndDocument();

}

void Riepilogo::loadResults(){

    QFile file("results.xml");
    if (!file.exists())
        return;

    if (!file.open(QIODevice::ReadOnly)){
        qWarning("Could not open file");
        return;
    }

    QXmlSimpleReader xmlReader;
    QXmlInputSource *source = new QXmlInputSource(&file);

    Handler *handler = new Handler;
    xmlReader.setContentHandler(handler);
    xmlReader.setErrorHandler(handler);

    bool ok = xmlReader.parse(source);

    if (!ok)
        qFatal("Parsing failed.");

    res = handler->getResults();
}
