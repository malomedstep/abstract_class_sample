#include <iostream>
using namespace std;

struct Data {
	int totalOrders;
	double maxOrderAmount;
	double averageOrderAmount;
	string lastOrderTime;
	string cashierName;
};

Data GetDataFromSomeSource() {
	return {
		147,
		192.50,
		36.10,
		"21:53",
		"John Doe"
	};
}

class BaseReporter {
public:
	virtual void PrintReport(Data data) = 0;
};

class XmlReporter : public BaseReporter {
public:
	void PrintReport(Data data) override {
		cout << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl
			<< "<Report>" << endl
			<< "  <TotalOrders>" << data.totalOrders << "</TotalOrders>" << endl
			<< "  <MaxOrderAmount>" << data.maxOrderAmount << "</MaxOrderAmount>" << endl
			<< "  <AverageOrderAmount>" << data.averageOrderAmount << "</AverageOrderAmount>" << endl
			<< "  <LastOrderTime>" << data.lastOrderTime << "</LastOrderTime>" << endl
			<< "  <CashierName>" << data.cashierName << "</CashierName>" << endl
			<< "</Report>" << endl;
	}
};

class JsonReporter : public BaseReporter {
public:
	void PrintReport(Data data) override {
		cout << "{" << endl
			<< "  \"totalOrders\": " << data.totalOrders << "," << endl
			<< "  \"maxOrderAmount\": " << data.maxOrderAmount << "," << endl
			<< "  \"averageOrderAmount\": " << data.averageOrderAmount << "," << endl
			<< "  \"lastOrderTime\": \"" << data.lastOrderTime << "\"," << endl
			<< "  \"cashierName\": \"" << data.cashierName << "\"" << endl
			<< "}" << endl;
	}
};

class PlainTextReporter : public BaseReporter {
public:
	void PrintReport(Data data) override {
		cout << "Total orders: " << data.totalOrders << endl
			<< "Max order amount: " << data.maxOrderAmount << endl
			<< "Average order amount: " << data.averageOrderAmount << endl
			<< "Last order time: " << data.lastOrderTime << endl
			<< "Cashier name: " << data.cashierName << endl;
	}
};

class DataProcessor {
private:
	BaseReporter* _reporter;

public:
	DataProcessor(BaseReporter* reporter) : _reporter(reporter) {}

	void ReadAndPrintData() {
		Data data = GetDataFromSomeSource();
		_reporter->PrintReport(data);
	}
};



int main()
{
	DataProcessor proc(new JsonReporter());
	proc.ReadAndPrintData();

	return 0;
}

