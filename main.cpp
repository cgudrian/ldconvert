#include <QCommandLineParser>
#include <QCoreApplication>
#include <QElapsedTimer>
#include <QFile>
#include <QStringTokenizer>
#include <QTextStream>
#include <QTimer>

bool parseLine(const QByteArray &data)
{
    if (data.isEmpty())
        return true;

    auto lineType = data[0] - '0';

    switch (lineType) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        return false;
    }

    return true;
}

bool parseFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QFile::ReadOnly))
        return false;

    forever {
        auto line = file.readLine();
        if (line.isEmpty())
            break;
        parseLine(line.trimmed());
    }

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCommandLineParser qlp;

    qlp.process(a);

    QTimer::singleShot(0, [] {
        QElapsedTimer timer;
        timer.start();
        parseFile("c:\\Users\\cgu\\Dropbox\\Lego\\models\\76989.mpd");
        qDebug() << timer.elapsed();
        qApp->quit();
    });

    return a.exec();
}
