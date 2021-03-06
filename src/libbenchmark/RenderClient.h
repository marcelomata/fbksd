/*
 * Copyright (c) 2019 Jonas Deyson
 *
 * This software is released under the MIT License.
 *
 * You should have received a copy of the MIT License
 * along with this program. If not, see <https://opensource.org/licenses/MIT>
 */

#ifndef RENDERCLIENT_H
#define RENDERCLIENT_H

#include "fbksd/core/definitions.h"

#include <vector>
#include <string>

namespace rpc { class client; }

namespace fbksd
{

class BenchmarkManager;

/**
 * \brief The RenderClient class is used by the BenchmarkManager to communicate with a rendering server
 *
 * \ingroup BenchmarkServer
 */
class RenderClient
{
public:
    RenderClient(int port);

    ~RenderClient();

    /**
     * @brief Queries the renderer for its tile size.
     */
    int getTileSize();

    /**
     * \brief Requests scene information from the rendering system. This information is obtained from the
     * current scene being rendered.
     *
     * \return SceneInfo
     */
    SceneInfo getSceneInfo();

    /**
     * \brief Informs the sample layout required by the ASR technique.
     *
     * \param[in] SampleLayout: layout
     */
    void setParameters(const SampleLayout& layout);

    /**
     * \brief Compute the samples values for the given samples positions.
     */
    TilePkg evaluateSamples(int64_t spp, int64_t remainingCount);

    TilePkg getNextTile(int64_t prevTileIndex);

    TilePkg evaluateInputSamples(int64_t spp, int64_t remainingCount);

    TilePkg getNextInputTile(int64_t prevTileIndex, bool prevWasInput);

    void lastTileConsumed(int64_t prevTileIndex);

    /**
     * \brief Finishes the rendering system for the current scene.
     */
    void finishRender();

private:
    std::unique_ptr<rpc::client> m_client;
};

} // namespace fbksd

#endif
