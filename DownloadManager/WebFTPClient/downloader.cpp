 #include <QtGui>
 #include <QMessageBox>
 #include <QNetworkRequest>
 #include <QNetworkReply>
 #include "downloader.h"

 Downloader::Downloader(QWidget *parentWidget, QNetworkAccessManager *manager)
     : QObject(parentWidget), manager(manager), parentWidget(parentWidget)
 {
 }

 QString Downloader::chooseSaveFile(const QUrl &url)
 {
     QString fileName = url.path().split("/").last();
     if (!path.isEmpty())
         fileName = QDir(path).filePath(fileName);

     return QFileDialog::getSaveFileName(parentWidget, tr("Save File"), fileName);
 }

 void Downloader::startDownload(const QNetworkRequest &request)
 {
     downloads[request.url().toString()] = chooseSaveFile(request.url());

     QNetworkReply *reply = manager->get(request);
     connect(reply, SIGNAL(finished()), this, SLOT(finishDownload()));
 }

 void Downloader::saveFile(QNetworkReply *reply)
 {
     QString newPath = downloads[reply->url().toString()];

     if (newPath.isEmpty())
         newPath = chooseSaveFile(reply->url());

     if (!newPath.isEmpty()) {
         QFile file(newPath);
         if (file.open(QIODevice::WriteOnly)) {
             file.write(reply->readAll());
             file.close();
             path = QDir(newPath).dirName();
             QMessageBox::information(parentWidget, tr("Download Completed"),
                                      tr("Saved '%1'.").arg(newPath));
         } else
             QMessageBox::warning(parentWidget, tr("Download Failed"),
                                  tr("Failed to save the file."));
     }
 }

 void Downloader::finishDownload()
 {
     QNetworkReply *reply = static_cast<QNetworkReply *>(sender());
     saveFile(reply);
     downloads.remove(reply->url().toString());
     reply->deleteLater();
 }
