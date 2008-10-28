#include "mapviewer.h"
/*!
 * \example mapviewer.cpp
 * This application is just a simple map viewer. A Mapadapter is created (OpenStreetmaps) 
 * and added to a layer. The layer is given to the MapControl.
 * Two Buttons are available to adjust the zoom level.
 * 
 * You can find this example here: MapAPI/Samples/Mapviewer
 * \image html sample_mapviewer.png "screenshot"
 */
Mapviewer::Mapviewer(QWidget *parent)
	: QMainWindow(parent)
{
	// create MapControl
	mc = new MapControl(QSize(380, 540));
   mc->showScale(true);
	
	// create mapadapter, for mainlayer and overlay
	mapadapter = new OSMMapAdapter();
	
	// create a layer with the mapadapter and type MapLayer
	mainlayer = new MapLayer("OpenStreetMap-Layer", mapadapter);
	
	// add Layer to the MapControl
	mc->addLayer(mainlayer);

	addZoomButtons();
	
	// show mapcontrol in mainwindow
	setCentralWidget(mc);
}
void Mapviewer::addZoomButtons()
{
	// create buttons as controls for zoom
	QPushButton* zoomin = new QPushButton("+");
	QPushButton* zoomout = new QPushButton("-");
	zoomin->setMaximumWidth(50);
	zoomout->setMaximumWidth(50);
	
	connect(zoomin, SIGNAL(clicked(bool)),
			  mc, SLOT(zoomIn()));
	connect(zoomout, SIGNAL(clicked(bool)),
			  mc, SLOT(zoomOut()));
	
	// add zoom buttons to the layout of the MapControl
	QVBoxLayout* innerlayout = new QVBoxLayout;
	innerlayout->addWidget(zoomin);
	innerlayout->addWidget(zoomout);
	mc->setLayout(innerlayout);
}


Mapviewer::~Mapviewer()
{
}

// resize the widget 
void Mapviewer::resizeEvent ( QResizeEvent * event )	
{
	//TODO: get inset size
	mc->resize(event->size()-QSize(20,30));
}
