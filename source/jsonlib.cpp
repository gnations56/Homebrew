//
// Created by gnations on 8/3/2019.
//

#include "jsonlib.h"

json_object * createJsonObject() {
	return json_object_new_object();
}

json_object * createInt(int value) {
	return json_object_new_int(value);
}

json_object * createString(const char* value) {
	return json_object_new_string(value);
}

void addChildToJsonObject(json_object *parent, char* keyname, json_object *child) {
	json_object_object_add(parent,keyname,child);
}
const char* getJsonString(json_object *parent) {
	return json_object_to_json_string(parent);
}

const char* getCall(json_object *json) {
	return json_object_get_string(json_object_object_get(json,"call"));
}

int getXOffset(json_object *json){
	return json_object_get_int(json_object_object_get(json,"xoffset"));
}
int getYOffset(json_object *json){
	return json_object_get_int(json_object_object_get(json,"yoffset"));
}
int getRadius(json_object *json){
	return json_object_get_int(json_object_object_get(json,"radius"));
}
int getWidth(json_object *json){
	return json_object_get_int(json_object_object_get(json,"width"));
}
int getHeight(json_object *json){
	return json_object_get_int(json_object_object_get(json,"height"));
}
Color getColor(json_object* json) {
	json_object *obj = json_object_object_get(json,"color");
	Color c;
	int rgba[4];
	for (int i = 0; i < 4; i++) {
		rgba[i] = json_object_get_int(json_object_array_get_idx(obj,i));
	}
	c.r = rgba[0];
	c.g = rgba[1];
	c.b = rgba[2];
	c.a = rgba[3];
	return c;
}

json_object * createArray(int value[4]) {
	json_object *object = json_object_new_array();
	for (int i = 0; i < 4; i++) {
		json_object_array_add(object,createInt(value[i]));
	}
	return object;
}

const char* createRenderObject(std::string call, int xpos, int ypos, int radius, int width, int height, Color c) {
	json_object *obj = createJsonObject();
	json_object *callStr = createString(call.c_str());
	json_object *xoffset = createInt(xpos);
	json_object *yoffset = createInt(ypos);
	json_object *r = createInt(radius);
	json_object *w = createInt(width);
	json_object *h = createInt(height);
	int rgba[4] = {c.r,c.g,c.b,c.a};
	int* rgbaptr;
	rgbaptr=rgba;
	json_object *color = createArray(rgbaptr);
	addChildToJsonObject(obj,"call",callStr);
	addChildToJsonObject(obj,"xoffset",xoffset);
	addChildToJsonObject(obj,"yoffset",yoffset);
	addChildToJsonObject(obj,"radius",r);
	addChildToJsonObject(obj,"width",w);
	addChildToJsonObject(obj,"height",h);
	addChildToJsonObject(obj,"color",color);
	return getJsonString(obj);
}