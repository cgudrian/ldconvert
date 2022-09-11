#include <QCommandLineParser>
#include <QCoreApplication>
#include <QElapsedTimer>
#include <QFile>
#include <QStringTokenizer>
#include <QTextStream>
#include <QTimer>

enum class LineType {
    MetaComment = 0,
    Reference = 1,
    Line = 2,
    Triangle = 3,
    Quad = 4,
    OptLine = 5,
};

bool parseLine(const QByteArray &data)
{
    if (data.isEmpty())
        return true;

    LineType lineType = static_cast<LineType>(data[0] - '0');

    switch (lineType) {
    case LineType::MetaComment:
        break;
    case LineType::Reference:
        break;
    case LineType::Line:
        break;
    case LineType::Triangle:
        break;
    case LineType::Quad:
        break;
    case LineType::OptLine:
        // ignore
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
