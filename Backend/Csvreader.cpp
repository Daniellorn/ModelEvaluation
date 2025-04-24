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
    std::string filenameStr = m_Path.string();
    std::string_view filename = filenameStr;

    LoadFile(m_Path, filename);

    PrintPath();

    if (filename.find("klasyfikacja") != std::string_view::npos)
    {
        emit fileLoaded(m_Data);
    }
    else
    {
        emit fileLoaded2(m_Data2);
    }

}

void CSVReader::LoadFile(const std::filesystem::path& path, const std::string_view filenameView)
{
    std::ifstream file(path);

    //int lol = 10;

    if (!file)
    {
        qDebug() << path.string();

        std::filesystem::path currentPath = std::filesystem::current_path();

        qDebug() << currentPath.string();

        throw std::runtime_error("Nie można otworzyć pliku: " + path.string());
    }

    std::string line;
    std::getline(file, line);

    if (filenameView.find("klasyfikacja") != std::string_view::npos)
    {
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

    if (filenameView.find("regresja") != std::string_view::npos)
    {
        while (std::getline(file, line))
        {
            std::istringstream stream(line);
            std::string real, expected1, expected2;

            std::getline(stream, real, ',');
            std::getline(stream, expected1, ',');
            std::getline(stream, expected2, ',');

            m_Data2.emplace_back(
                DataRow2{std::stof(real),std::stof(expected1),std::stof(expected2)});

            //lol--;
            //if (lol <= 0) return;
        }
    }
}

int CSVReader::EncodeValues(const std::string& value)
{
    if (value == "<=50K") return 0;
    if (value == ">50K") return 1;

    throw std::invalid_argument("Nieprawidłowa wartość: " + value);

}
