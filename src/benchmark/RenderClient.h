#ifndef RENDERCLIENT_H
#define RENDERCLIENT_H

#include "fbksd/core/Definitions.h"
#include "fbksd/core/RPC.h"

#include <vector>
#include <string>

class BenchmarkManager;
class QTcpServer;
class QTcpSocket;


/**
 * \brief The RenderClient class is used by the BenchmarkManager to communicate with a rendering server
 *
 * \ingroup BenchmarkServer
 */
class RenderClient: public RPCClient
{
public:
    RenderClient(BenchmarkManager* manager, int port);

    /**
     * \brief Requests scene information from the rendering system. This information is obtained from the
     * current scene being rendered.
     *
     * \return SceneInfo
     */
    SceneInfo getSceneInfo();

    /**
     * \brief Detaches shared memory
     */
    void detachMemory();

    /**
     * \brief Informs the sample layout required by the ASR technique.
     *
     * \param[in] SampleLayout: layout
     */
    void setParameters(int maxSPP, const SampleLayout& layout);

    /**
     * \brief Compute the samples values for the given samples positions.
     *
     * \param[in] isSPP         Flag indicating the unit of `numSamples`.
     * \param[in] numSamples    Number of samples.
     * \param[in] inSize        Number of features in the samples array.
     * \param[in] samples       Input sample values.
     * \param[in] outSize       Number of features in the output array.
     * \param[out] output       Output sample values.
     * \return Number of samples evaluated.
     */
    int evaluateSamples(bool isSPP, int numSamples);

    /**
     * \brief Overloaded method.
     *
     * Receives a CropWindow that specifies the region where the samples must be located.
     */
    int evaluateSamples(bool isSPP, int numSamples, const CropWindow& crop);

    /**
     * \brief Overloaded method.
     *
     * Receives a pdf that specifies distribution that the samples should follow.
     */
    int evaluateAdaptiveSamples(bool isSPP, int numSamples);

    /**
     * \brief Finishes the rendering system for the current scene.
     */
    void finishRender();

private:
    BenchmarkManager *manager;
    QTcpSocket *current_connection;
};


#endif
