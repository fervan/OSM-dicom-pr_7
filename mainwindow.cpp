#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>

// Program chwilowo bazuje na poni¿szej clasie

/**
* Copyright 1997 Serge Derhy
*
* Dicom Decoder package was written and released by :
* <P>
* <CENTER>
*                                  Serge Derhy	<BR>
*                                  25 RUE SPONTINI<BR>
*                                  75116 Paris<BR>
*                                  France<P>
*
*                                Phone: 331 45 53 84 07<BR>
*								 331(0)1 45 08 94 84
*                                sderhy@imaginet.fr<P>
* </CENTER>
* Selling the code for this program without prior written consent is
* expressly forbidden.  In other words, please ask first before you try and
* make money off of my program.
*
* This package is provided WITHOUT ANY WARRANTY either expressed or implied.
* You may study, use, modify, and distribute it for non-commercial purposes
* as long as this copyright notice remain intact.
**/

///////////////////////////////////////////////////////////////////////////////
// ============================================================================
class CDicomDir {

      public:
             const static int MAX_HEADER_SIZE = 10000;
              short int* data;
               int dlugoscData;
                int index;
                 int lenght;

             CDicomDir( short int*, int );
              int szukajPozycji( int, int, int );
               int odczytajPozycje ( int );
                int odczytajInt16 ( int );
                 char* pobierzText ( int, int, int );
             ~CDicomDir();
};
// ============================================================================
///////////////////////////////////////////////////////////////////////////////
CDicomDir::CDicomDir( short int* array, int zakres ) {
        this->data = new short int[ zakres ];
         for ( int i = 0; i < zakres; i++ )
               this->data[i] = array[i];
        this->dlugoscData = zakres;
         this->index = 0;
          this->lenght = 0;
};
///////////////////////////////////////////////////////////////////////////////
char* CDicomDir::pobierzText( int gE, int dE, int j ) {
      int pozycja = szukajPozycji ( gE, dE, j );
      if ( pozycja < MAX_HEADER_SIZE && pozycja != -1 ) {
           int dlugosc = odczytajPozycje ( pozycja + 4 );
            if ( dlugosc > 256 ) dlugosc = odczytajInt16( pozycja + 6 );
             if ( dlugosc > 64 || dlugosc < 0 ) dlugosc = 64;
              if ( dlugosc > ( dlugoscData - pozycja - 8 ) )
                   dlugosc = dlugoscData - pozycja - 9;
           index = pozycja;
            pozycja += 8;
             lenght = dlugosc;
           char* patchName = new char[ dlugosc + 1 ];
           for ( int i = 0; i < dlugosc; i++ )
                 patchName[i] = ( char ) data[pozycja++];
                  patchName[dlugosc] = '\0';
          return patchName;
      }
      else return "Nie rozpoznano danych pacjenta.";
};
///////////////////////////////////////////////////////////////////////////////
int CDicomDir::szukajPozycji( int gE, int dE, int j ) {
    long LenMax = dlugoscData - 3;
     bool found = false;
    short int _1 = gE & 0xff;
     short int _2 = ( gE & 0xff00 ) >> 8;
      short int _3 = dE & 0xff;
       short int _4 = ( dE & 0xff00 ) >> 8;

    for ( ; j < LenMax || found ; j++ )
        if ( (   data[j] == _1 ) &&
              ( data[j+1] == _2 ) &&
               ( data[j+2] == _3 ) &&
                ( data[j+3] == _4 ) ) {
                  found = true;
                  return j;
             }
 return -1;
};
///////////////////////////////////////////////////////////////////////////////
int CDicomDir::odczytajPozycje( int i ) {
    int _0 = (int) ( data[i]     & 0xff);
     int _1 = (int) ( data[i + 1] & 0xff);
      int _2 = (int) ( data[i + 2] & 0xff);
       int _3 = (int) ( data[i + 3] & 0xff);
 return _3 << 24 | _2 << 16 | _1 << 8 | _0 ;
};
///////////////////////////////////////////////////////////////////////////////
int CDicomDir::odczytajInt16 ( int i ) {
        int _1 = data[i + 1] & 0xff;
         int _0 = data[i]     & 0xff;
          int anInt = _1 << 8 | _0;
     if ( anInt < -1 )
           anInt = ( int ) ( data[i] * 256 ) & 0xff +
                              data[i + 1] & 0xff;
 return anInt;
};
///////////////////////////////////////////////////////////////////////////////
CDicomDir::~CDicomDir( ) {
 delete [] data;
};
///////////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->actionOtw_rz_Dicom, SIGNAL(triggered()), this, SLOT( czytajDicomPlik() ));
    QObject::connect(ui->actionO_Programie, SIGNAL(triggered()), this, SLOT( oProgramie() ));

  //  QStringList headers;
  //  headers << "Item" << "String";
  //  ui->treeWidget->setHeaderLabels(headers);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::czytajDicomPlik() {

     QString fileName(QFileDialog::getOpenFileName());

     QByteArray ba = fileName.toLatin1();
     const char *file = ba.data();

    if (  fopen(file, "rb") != NULL ) {

            ui->treeWidget->clear();

                 FILE* fp;
                  fp = fopen(file, "rb");

                 int lengh = 0;
                  short int _buff;
                   while ( fscanf(fp,"%1c",&_buff) != EOF ) lengh++;
                 fclose(fp);

                 FILE* fk;
                  fk = fopen(file, "rb");
                 short int* buffer = new short int[ ++lengh ];
                  int j = 0;
                   while ( fscanf(fk,"%1c",&buffer[j++]) != EOF );
                 fclose(fk);

                  CDicomDir *cdir = new CDicomDir( buffer, lengh+1 );

                  ////////////////////////////////////
                  // seria kilku przyk³adowych item'ów
                  ////////////////////////////////////

                  QTreeWidgetItem *track1 = new QTreeWidgetItem(ui->treeWidget);
                  track1->setText(0, "0x0008 / 0x0008");
                  track1->setText(1, cdir->pobierzText(0x0008,0x0008,0) );

                  QTreeWidgetItem *track2 = new QTreeWidgetItem(ui->treeWidget);
                  track2->setText(0, "0x0008 / 0x0060");
                  track2->setText(1, cdir->pobierzText(0x0008,0x0060,0) );

                  QTreeWidgetItem *track3 = new QTreeWidgetItem(ui->treeWidget);
                  track3->setText(0, "0x0008 / 0x0080");
                  track3->setText(1, cdir->pobierzText(0x0008,0x0080,0) );

                 QTreeWidgetItem *track4 = new QTreeWidgetItem(ui->treeWidget);
                 track4->setText(0, "0x0010 / 0x0010");
                 track4->setText(1, cdir->pobierzText(0x0010,0x0010,0) );

                 QTreeWidgetItem *track5 = new QTreeWidgetItem(ui->treeWidget);
                 track5->setText(0, "0x0010 / 0x0020");
                 track5->setText(1, cdir->pobierzText(0x0010,0x0020,0) );

                 QTreeWidgetItem *track6 = new QTreeWidgetItem(ui->treeWidget);
                 track6->setText(0, "0x0010 / 0x0030");
                 track6->setText(1, cdir->pobierzText(0x0010,0x0030,0) );

                 QTreeWidgetItem *track7 = new QTreeWidgetItem(ui->treeWidget);
                 track7->setText(0, "0x0010 / 0x0040");
                 track7->setText(1, cdir->pobierzText(0x0010,0x0040,0) );

                 QTreeWidgetItem *track8 = new QTreeWidgetItem(ui->treeWidget);
                 track8->setText(0, "0x0020 / 0x4000");
                 track8->setText(1, cdir->pobierzText(0x0020,0x4000,0) );

                 QTreeWidgetItem *track9 = new QTreeWidgetItem(ui->treeWidget);
                 track9->setText(0, "0x0028 / 0x0004");
                 track9->setText(1, cdir->pobierzText(0x0028,0x0004,0) );

                 QTreeWidgetItem *track10 = new QTreeWidgetItem(ui->treeWidget);
                 track10->setText(0, "0x0028 / 0x0030");
                 track10->setText(1, cdir->pobierzText(0x0028,0x0030,0) );

                 ui->treeWidget->repaint();


           } else {
                    QMessageBox(QMessageBox::Warning, "Warning", "Wyst¹pi³ BL¥D!").exec();
                  }



}

void MainWindow::oProgramie() {
    QMessageBox( QMessageBox::Information, "O Programie...",
                 "Projekt_OSM(7) \n"
                 "dn. 21.04.2010 \n"
                 "v1.2 \n"
                 " \n"
                 "Roman Modzelewski \n"
                 "Michal Losicki \n"
                 "Lukasz Zeleznicki \n").exec();
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
