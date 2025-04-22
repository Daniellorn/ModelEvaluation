#include "Csvreader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <QDebug>

CSVReader::CSVReader()
{
}

std::vector<DataRow>& CSVReader::GetData()
{
    return m_Data;
}

void CSVReader::PrintData()
{
    if (m_Data.empty())
    {
        qDebug() << "Pusty plik\n";
    }

    for (auto& row: m_Data)
    {
        qDebug() << row.income << " " << row.C50_PV << " " << row.C50_prob1 << " " << row.rf_PV << " " << row.rf_prob1 << "\n";
    }
}

void CSVReader::PrintPath()
{
    qDebug() << m_Path.string();
}

void CSVReader::loadFileSlot(const QString& filePath)
{
    m_Path = filePath.toStdString();
    LoadFile(m_Path);

    PrintPath();

    emit fileLoaded(m_Data);

}

void CSVReader::LoadFile(const std::filesystem::path& path)
{
    std::ifstream file(path);

    //int lol = 10;

    if (!file)
    {
        throw std::runtime_error("Nie można otworzyć pliku: " + path.string());
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::istringstream stream(line);
        std::string Sincome, Sc50_pv, Sc50_prob1, Srf_pv,  Srf_prob1;

        std::getline(stream, Sincome, ',');
        std::getline(stream, Sc50_pv, ',');
        std::getline(stream, Sc50_prob1, ',');
        std::getline(stream, Srf_pv, ',');
        std::getline(stream, Srf_prob1, ',');

        m_Data.emplace_back(
            DataRow{EncodeValues(Sincome),EncodeValues(Sc50_pv),std::stof(Sc50_prob1),EncodeValues(Srf_pv),std::stof(Srf_prob1)});

        //lol--;
        //if (lol <= 0) return;
    }
}

int CSVReader::EncodeValues(const std::string& value)
{
    if (value == "<=50K") return 0;
    if (value == ">50K") return 1;

    throw std::invalid_argument("Nieprawidłowa wartość: " + value);

}
