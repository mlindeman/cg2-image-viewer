/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#ifndef QT_NO_PRINTER
#include <QPrinter>
#endif

#include "fstream"

class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
class QTextEdit;
class QVBoxLayout;
class QTabWidget;
class QPushButton;
class QSpinBox;

class ImageViewer : public QMainWindow{
  Q_OBJECT

private:

  //GUI Objects
  QWidget* m_option_panel1;
  QVBoxLayout* m_option_layout1;

  QWidget* m_option_panel2;
  QVBoxLayout* m_option_layout2;

  QPushButton* button1;
  QPushButton* button2;
  QSpinBox* spinbox1;



  private slots:

  //SLOTS
  void applyExampleAlgorithm();




  void open();
  void print();
  void zoomIn();
  void zoomOut();
  void normalSize();
  void fitToWindow();
  void about();

public:
  ImageViewer();
  bool loadFile(const QString &);
  void updateImageDisplay();

protected:

  void resizeEvent(QResizeEvent * event);

private:
  void generateControlPanels();


  void startLogging();
  void generateMainGui();

  void createActions();
  void createMenus();
  void updateActions();
  void scaleImage(double factor);
  void adjustScrollBar(QScrollBar *scrollBar, double factor);
  void renewLogging();

  QTabWidget* tabWidget;
  QTextEdit* logBrowser;
  QWidget* centralwidget;
  QLabel* imageLabel;
  QScrollArea* scrollArea;
  double scaleFactor;
  QImage* image;

  std::fstream logFile;

  #ifndef QT_NO_PRINTER
  QPrinter printer;
  #endif

  QAction *openAct;
  QAction *printAct;
  QAction *exitAct;
  QAction *zoomInAct;
  QAction *zoomOutAct;
  QAction *normalSizeAct;
  QAction *fitToWindowAct;
  QAction *aboutAct;
  QAction *aboutQtAct;

  QMenu *fileMenu;
  QMenu *viewMenu;
  QMenu *helpMenu;
};

#endif
