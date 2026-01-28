#include <QCoreApplication>
#include <QUrl>

#include "Qt/Server/Server.h"


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    webrtsp::qt::Config config;
    config.streamers =
        {
            {
                QUrl::toPercentEncoding(QStringLiteral("Štrbské pleso")).toStdString(),
                {
                    .type = webrtsp::qt::StreamerConfig::Type::ReStreamer,
                    .uri = "rtsp://stream.strba.sk:1935/strba/VYHLAD_JAZERO.stream",
                    .description = "rtsp://stream.strba.sk:1935/strba/VYHLAD_JAZERO.stream",
                    .forceH264ProfileLevelId = "42c015",
                }
            },
            {
                QUrl::toPercentEncoding(QStringLiteral("Western Cape")).toStdString(),
                {
                    .type = webrtsp::qt::StreamerConfig::Type::ReStreamer,
                    .uri = "rtsp://196.21.92.82/axis-media/media.amp",
                    .description = "rtsp://196.21.92.82/axis-media/media.amp",
                    .forceH264ProfileLevelId = "42c015",
                }
            },
            {
                QUrl::toPercentEncoding(QStringLiteral("Nordland")).toStdString(),
                {
                    .type = webrtsp::qt::StreamerConfig::Type::ReStreamer,
                    .uri = "rtsp://77.110.228.219/axis-media/media.amp",
                    .description = "rtsp://77.110.228.219/axis-media/media.amp",
                    .forceH264ProfileLevelId = "42c015",
                }
            },
            {
                QUrl::toPercentEncoding(QStringLiteral("Price Center Plaza")).toStdString(),
                {
                    .type = webrtsp::qt::StreamerConfig::Type::ReStreamer,
                    .uri = "rtsp://132.239.12.145:554/axis-media/media.amp",
                    .description = "rtsp://132.239.12.145:554/axis-media/media.amp",
                    .forceH264ProfileLevelId = "42c015",
                }
            }
        };
    config.authToken = "token";

    webrtsp::qt::Server webRTSPServer(&config);

    return app.exec();
}
