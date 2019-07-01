#include "saver.h"
Saver::Saver(QObject *parent) : QObject(parent)
{
    file=new QFile(filename);
}

bool Saver::exists()
{
    QFileInfo path("./Time.txt");
    if(!path.exists())
    {
        file->open(QIODevice::ReadWrite);
        file->close();
    }
    file->setPermissions(QFile::ReadOwner|QFile::WriteOwner|QFile::ExeOwner|QFile::ReadGroup|QFile::ExeGroup|QFile::ReadOther|QFile::ExeOther);
    checked= path.exists()&&path.isFile()&&
            path.isReadable()&&path.isWritable();
    return checked;
}

void Saver::load()
{

    if(file->open(QIODevice::ReadOnly))
    {

        QTextStream in(file);
        STime=in.readLine();
        tTime=QTime::fromString(STime);
        file->close();
    }
}



void Saver::save(QString T)
{
    STime=T;
    if(file->open(QIODevice::ReadWrite))
    {
        QTextStream stream(file);
        stream<<STime;
        file->close();
    }
}

bool Saver::getChecked() const
{
    return checked;
}

QTime Saver::getTTime()
{
    load();
    return tTime;
}

