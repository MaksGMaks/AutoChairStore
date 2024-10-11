#include <QCoreApplication>
#include <QFile>
#include <QByteArray>
#include <QString>
#include <iostream>

QString removeQuotes(const QString& input) {
    QString result = input;
    if (result.startsWith('\"') && result.endsWith('\"')) {
        result = result.mid(1, result.length() - 2);
    } else if (result.startsWith('\'') && result.endsWith('\'')) {
        result = result.mid(1, result.length() - 2);
    }
    return result;
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    if (argc != 2) {
        std::cerr << "Usage: ./prog path_to_image" << std::endl;
        return -1;
    }

    QString filePath = argv[1];
    filePath = removeQuotes(filePath);

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Could not open the file: " << filePath.toStdString() << std::endl;
        return -1;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QString hexData = fileData.toHex();

    QFile outputFile("output.txt");
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << "Could not open output.txt for writing" << std::endl;
        return -1;
    }

    QTextStream out(&outputFile);
    out << hexData;
    outputFile.close();

    std::cout << "Hex data has been written to output.txt" << std::endl;

    return 0;
}
