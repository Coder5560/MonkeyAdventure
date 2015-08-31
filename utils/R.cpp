#pragma once

#include "R.h"





float R::Constants::musicVolumn = 1;
float R::Constants::soundVolumn = 1;
bool R::Constants::musicEnable = true;
bool R::Constants::soundEnable = true;





void R::Utils::resetGameVariable() {

}
void R::Utils::loadGameVariable() {

}

void R::Utils::updateGameVariable() {

}

void R::Utils::checkNetwork(const std::function<void(bool hasNetwork)> &callback){

	network::HttpRequest* request = new (std::nothrow) network::HttpRequest();
	request->setUrl("https://www.google.com");
	request->setRequestType(network::HttpRequest::Type::GET);
	request->setResponseCallback([=](network::HttpClient* client, network::HttpResponse* response)
	{
		cocos2d::log("response is %s", response ? "true" : "false");
		cocos2d::log("response->isSucceed() is %s", response->isSucceed() ? "true" : "false");

		if (!response || !response->isSucceed())
		{
			// No internet connection
			cocos2d::log("No internet connection");
			if(callback)callback(false);
		}
		else
		{
			// Internet available
			cocos2d::log("Internet connection available");
			if (callback)callback(true);
		}
	});

	network::HttpClient::getInstance()->sendImmediate(request);
	request->release();
}