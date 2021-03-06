#include "NoiseStreamerMenuContainer.h"
#include "NoiseStreamerAgentMenuItem.h"
#include "NoiseStreamerAgentClientMenuItem.h"
#include "SineWaveGeneratorMenuItem.h"
#include "AlsaCaptureMenuItem.h"

NoiseStreamerMenuContainer::NoiseStreamerMenuContainer() : MenuContainer(
	6,
	"nss",
	"Noise Streamer")
{
	this->setContinueQuestion(true);
}

NoiseStreamerMenuContainer::~NoiseStreamerMenuContainer()
{

}

void NoiseStreamerMenuContainer::fillOptions()
{
	this->addMenuItem(new NoiseStreamerAgentMenuItem(logSrv));
	this->addMenuItem(new NoiseStreamerAgentClientMenuItem(logSrv));
	this->addMenuItem(new SineWaveGeneratorMenuItem(logSrv));
	this->addMenuItem(new AlsaCaptureMenuItem(logSrv));
}

string NoiseStreamerMenuContainer::getHeader()
{
	return "";
}

/*

.##....##..#######..####..######..########.....######.....
.###...##.##.....##..##..##....##.##..........##....##....
.####..##.##.....##..##..##.......##..........##..........
.##.##.##.##.....##..##...######..######.......######.....
.##..####.##.....##..##........##.##................##....
.##...###.##.....##..##..##....##.##..........##....##.###
.##....##..#######..####..######..########.....######..###


.%%..%%...%%%%...%%%%%%...%%%%...%%%%%%...........%%%%..........
.%%%.%%..%%..%%....%%....%%......%%..............%%.............
.%%.%%%..%%..%%....%%.....%%%%...%%%%.............%%%%..........
.%%..%%..%%..%%....%%........%%..%%..................%%....%%...
.%%..%%...%%%%...%%%%%%...%%%%...%%%%%%...........%%%%.....%%...
................................................................


888b    888        d8b                    .d8888b.
8888b   888        Y8P                   d88P  Y88b
88888b  888                              Y88b.
888Y88b 888 .d88b. 888.d8888b  .d88b.     "Y888b.
888 Y88b888d88""88b88888K     d8P  Y8b       "Y88b.
888  Y88888888  888888"Y8888b.88888888         "888
888   Y8888Y88..88P888     X88Y8b.       Y88b  d88Pd8b
888    Y888 "Y88P" 888 88888P' "Y8888     "Y8888P" Y8P



 _           _                   _
(_) _       (_)                 (_)
(_)(_)_     (_)    _  _  _    _  _     _  _  _  _     _  _  _  _
(_)  (_)_   (_) _ (_)(_)(_) _(_)(_)  _(_)(_)(_)(_)   (_)(_)(_)(_)_
(_)    (_)_ (_)(_)         (_)  (_) (_)_  _  _  _   (_) _  _  _ (_)
(_)      (_)(_)(_)         (_)  (_)   (_)(_)(_)(_)_ (_)(_)(_)(_)(_)
(_)         (_)(_) _  _  _ (_)_ (_) _  _  _  _  _(_)(_)_  _  _  _
(_)         (_)   (_)(_)(_)  (_)(_)(_)(_)(_)(_)(_)    (_)(_)(_)(_)


   _  _  _  _
 _(_)(_)(_)(_)_
(_)          (_)
(_)_  _  _  _
 (_)(_)(_)(_)_
 _           (_)  _  _
(_)_  _  _  _(_) (_)(_)
  (_)(_)(_)(_)   (_)(_)




  =========================================================
  =  =======  =================================      ======
  =   ======  ================================  ====  =====
  =    =====  ================================  ====  =====
  =  ==  ===  ===   ===  ===   ====   =========  ==========
  =  ===  ==  ==     ======  =  ==  =  ==========  ========
  =  ====  =  ==  =  ==  ===  ====     ============  ======
  =  =====    ==  =  ==  ====  ===  ==========  ====  =====
  =  ======   ==  =  ==  ==  =  ==  =  =======  ====  ==  =
  =  =======  ===   ===  ===   ====   =========      ===  =
  =========================================================





  `...     `..                                 `.. ..
  `. `..   `..           `.                  `..    `..
  `.. `..  `..   `..        `....    `..      `..
  `..  `.. `.. `..  `.. `..`..     `.   `..     `..
  `..   `. `..`..    `..`..  `... `..... `..       `..
  `..    `. .. `..  `.. `..    `..`.         `..    `..
  `..      `..   `..    `..`.. `..  `....      `.. ..  `..


*/
