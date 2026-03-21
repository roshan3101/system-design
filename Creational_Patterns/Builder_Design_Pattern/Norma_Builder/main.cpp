#include <bits/stdc++.h>
using namespace std;

class HTTPRequest 
{
	private:
		string url;
		string method;
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
		HTTPRequestBuilder& setURL(const string& url) {
			request.url = url;
			return *this;
		}
		
		HTTPRequestBuilder& setMethod(const string& method) {
			request.method = method;
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
			if(request.url.empty()) {
				throw runtime_error("URL is required");
			}
			
			if(request.method.empty()) {
				request.method = "GET"; // Default method
			}
			return request;
		}
};


int main() 
{
	try {
		HTTPRequest request = HTTPRequestBuilder()
			.setURL("https://api.example.com/data")
			.setMethod("POST")
			.setBody("{\"key\": \"value\"}")
			.addHeader("Content-Type", "application/json")
			.addQueryParam("version", "1.0")
			.build();
		
		request.execute();
	} catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
	
	return 0;
}