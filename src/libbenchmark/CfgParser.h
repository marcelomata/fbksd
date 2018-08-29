#ifndef SCENEFILE_H
#define SCENEFILE_H

#include "fbksd/core/SceneInfo.h"

#include <QString>
#include <QVector>


struct BenchmarkConfig
{
public:
    struct Scene
    {
        QString name;
        QString path;
        QVector<int> spps;
        SceneInfo info;
    };

    struct Renderer
    {
        QString name;
        QString path;
        int port;
        QVector<Scene> scenes;
    };

    QVector<Renderer> renderers;
};


/**
 * @brief Loads data from the configuration file.
 *
 * @returns A BenchmarkConfig object with the data.
 * @throws std::runtime_error in case of error reading the configuration file.
 */
BenchmarkConfig loadConfig(const QString& filePath);


#endif // SCENEFILE_H