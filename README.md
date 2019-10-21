# ofxWebServer

My (perevalovds) modification of ofxWebServer, adopted to compiling on Windows, oF 0.10.1.

## Features
Webserver implementation using mongoose.

You can serve files from your data folder or write c++ code that gets triggered by URL requests.

## Examples

* example - an example which creates webpage with controls for changing oF application's background color.

* example_sendscreen - this example demonstrates sending oF screen to webpage 
and also sending mouse clicks from web.
It uses ofxKu addon for base64 encoding (only ofxKuUtilsBase64.h,.cpp files are required).