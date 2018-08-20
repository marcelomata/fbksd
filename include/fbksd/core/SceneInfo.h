#ifndef SCENEINFO_H
#define SCENEINFO_H

#include <map>
#include <string>
class QDataStream;


/**
 * \brief The SceneInfo class gives information about the scene being rendered.
 *
 * The SceneInfo class stores information about the scene being rendered.
 * You can use this information to tune the parameters of your algorithm.
 *
 * For example, to get the image size and to know if the scene has depth-of-field and motion blur,
 * you do the following:
 * \snippet SceneInfo_snippet.cpp 0
 *
 * The available query names are listed in the table below.
 *
    | Query             | Type       |
    | ------------------|------------|
    | width             | int        |
    | height            | int        |
    | has_motion_blur   | bool       |
    | has_dof           | bool       |
    | max_samples       | int        |
    | max_spp           | int        |
    | shutter_open      | float      |
    | shutter_close     | float      |

    \ingroup Core
 */
class SceneInfo
{
public:
    /**
     * \brief Get the a value with type T and key name, returns def if now found.
     */
    template<typename T>
    T get(const std::string& name) const;

    /**
     * \brief Set the a value with type T, key name, and value.
     */
    template<typename T>
    void set(const std::string& name, const T& value);

    /**
     * \brief Add all items from scene.
     *
     * If this SceneInfo and `scene` have items with the same key, they will be overwritten.
     */
    SceneInfo merged(const SceneInfo& scene) const;

private:
    friend QDataStream& operator<<(QDataStream& stream, const SceneInfo& layout);
    friend QDataStream& operator>>(QDataStream& stream, SceneInfo& layout);

    std::map<std::string, int> intMap;
    std::map<std::string, float> floatMap;
    std::map<std::string, bool> boolMap;
    std::map<std::string, std::string> stringMap;
};

#endif