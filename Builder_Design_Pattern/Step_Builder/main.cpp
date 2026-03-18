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


class MethodStep;
class BodyStep;
class OptionalStep;

class URLStep
{
	public:
		virtual MethodStep& setURL(const string& url) = 0;
};

class MethodStep
{
	public:
		virtual BodyStep& setMethod(const string& method) = 0;
};

class BodyStep
{
	public:
		virtual OptionalStep& setBody(const string& body) = 0;
};

class OptionalStep
{
	public:
		virtual OptionalStep& addHeader(const string& key, const string& value) = 0;
		virtual OptionalStep& addQueryParam(const string& key, const string& value) = 0;
		virtual HTTPRequest build() = 0;
};

class HTTPRequestBuilder : public URLStep, public MethodStep, public BodyStep, public OptionalStep
{
	private:
		HTTPRequest request;
		
	public:
		MethodStep& setURL(const string& url) override {
			request.url = url;
			return *this;
		}
		
		BodyStep& setMethod(const string& method) override {
			request.method = method;
			return *this;
		}
		
		OptionalStep& setBody(const string& body) override {
			request.body = body;
			return *this;
		}
		
		OptionalStep& addHeader(const string& key, const string& value) override {
			request.headers[key] = value;
			return *this;
		}
		
		OptionalStep& addQueryParam(const string& key, const string& value) override {
			request.queryParams[key] = value;
			return *this;
		}
		
		HTTPRequest build() override {
			return request;
		}
};

int main() {
	HTTPRequest request = HTTPRequestBuilder()
							.setURL("https://api.example.com/data")
							.setMethod("POST")
							.setBody("{\"key\": \"value\"}")
							.addHeader("Content-Type", "application/json")
							.addQueryParam("version", "1.0")
							.build();
							
	request.execute();
	
	return 0;
}