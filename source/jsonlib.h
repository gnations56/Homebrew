//
// Created by gnations on 8/3/2019.
//
#include "masterinc.h"

#ifndef HOMEBREW_JSONLIB_H
#define HOMEBREW_JSONLIB_H

json_object * createJsonObject();
json_object * createInt(int value);
json_object * createString(const char* value);
json_object * createArray(int value[4]);
void addChildToJsonObject(json_object *parent, char* keyname, json_object *child);
const char* getJsonString(json_object *parent);
const char* getCall(json_object *json);
int getXOffset(json_object *json);
int getYOffset(json_object *json);
int getRadius(json_object *json);
int getWidth(json_object *json);
int getHeight(json_object *json);
Color getColor(json_object *json);
const char* createRenderObject(std::string call, int xpos, int ypos, int radius, int width, int height, Color c);
#endif //HOMEBREW_JSONLIB_H
