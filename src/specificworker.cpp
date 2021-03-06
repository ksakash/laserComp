/*
 *    Copyright (C) 2018 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "specificworker.h"

/**
* \brief Default constructor
*/
SpecificWorker::SpecificWorker(MapPrx& mprx) : GenericWorker(mprx)
{

}

/**
* \brief Default destructor
*/
SpecificWorker::~SpecificWorker()
{
	
}

bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params)
{



	
	timer.start(Period);
	

	return true;
}

void SpecificWorker::compute()
{
	try
	{
		RoboCompLaser::TLaserData ldata = laser_proxy->getLaserData();
        std::sort( ldata.begin(), ldata.end(), [](RoboCompLaser::TData a, RoboCompLaser::TData b){ return a.dist < b.dist; }) ;
		// for(int i = 0; i < ldata.size(); i++)
		// {
		// 	std::cerr << "Ray Index: " << i << " Ray Range: " << ldata[i].dist << " Ray Angle: " << ldata[i].angle << std::endl;
		// }
		std::cout << "Eatablished contact with the Gazebo!!" << std::endl;

	}
	catch(const Ice::Exception &e)
	{
		std::cout << "Error reading from Laser" << e << std::endl;
	}
}







