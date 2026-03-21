#include <bits/stdc++.h>
using namespace std;

class HTTPRequest 
{
	private:
		string method;
		string url;
		string body;
		map<string, string> headers;
		map<string, string> queryParams;
		
		HTTPRequest() {}
		
	public:
		friend class HTTPRequestBuilder;
		
		void execute() {
			cout << "Executing HTTP Request:" << endl;
			if(url.empty() == false)
			{
				cout << "URL: " << url << endl;
			}
			
			if(!method.empty())
			{
				cout << "Method: " << method << endl;
			}
			if(!body.empty())
			{
				cout << "Body: " << body << endl;
			}
			
			if(!headers.empty())
			{
				cout << "Headers: " << endl;
				for (const auto& header : headers) {
					cout << header.first << ": " << header.second << endl;
				}
			}
			
			if(!queryParams.empty())
			{
				cout << "Query Parameters: " << endl;
				for (const auto& param : queryParams) {
					cout << param.first << ": " << param.second << endl;
				}
			}
		}
};


class HTTPRequestBuilder
{
	private:
		HTTPRequest request;
		
	public:
		HTTPRequestBuilder& setMethod(const string& method) {
			request.method = method;
			return *this;
		}
		
		HTTPRequestBuilder& setURL(const string& url) {
			request.url = url;
			return *this;
		}
		
		HTTPRequestBuilder& setBody(const string& body) {
			request.body = body;
			return *this;
		}
		
		HTTPRequestBuilder& addHeader(const string& key, const string& value) {
			request.headers[key] = value;
			return *this;
		}
		
		HTTPRequestBuilder& addQueryParam(const string& key, const string& value) {
			request.queryParams[key] = value;
			return *this;
		}
		
		HTTPRequest build() {
			return request;
		}
};

class HTTPRequestDirector
{
	public:
		static HTTPRequest createGetRequest(const string& url) {
			return HTTPRequestBuilder().setMethod("GET").setURL(url).build();
		}
		
		static HTTPRequest createPostRequest(const string& url, const string& body) {
			return HTTPRequestBuilder().setMethod("POST").setURL(url).setBody(body).build();
		}
};

int main() {
	HTTPRequest getRequest = HTTPRequestDirector::createGetRequest("https://api.example.com/data");
	getRequest.execute();
	
	cout << endl;
	
	HTTPRequest postRequest = HTTPRequestDirector::createPostRequest("https://api.example.com/data", "{\"name\": \"John\"}");
	postRequest.execute();
	
	return 0;
}