#ifndef HASHMARKETAPI_H
#define HASHMARKETAPI_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;
class QNetworkRequest;
class QUrl;

class HashMarketApi : public QObject
{
        Q_OBJECT
    public:
        explicit HashMarketApi(QObject *parent = 0);

        void refresh();

    signals:
        void updateMarket(const QString &market,const QString &price);

    public slots:

        void bittrexFinished();
        void ccexFinished();
        void poloniexFinished();




    private:


        void bittrex();
        void ccex();
        void poloniex();

      


        QNetworkAccessManager *nam;
        QJsonObject result(QNetworkReply *reply );
        QString market;
        int marketId;


};

#endif // HASHMARKETAPI_H
