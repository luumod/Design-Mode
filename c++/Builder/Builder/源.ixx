#include <iostream>
#include <string>
#include <vector>
#include <vld.h>

//具体产品：电脑
class Computer {
public:
	Computer(const std::string& cpu, const std::string& ram) {
		this->cpu = cpu;
		this->ram = ram;
	}
	~Computer() {}
	void setMouse(const std::string& mouse) {
		this->mouse = mouse;
	}
	void setKeyboard(const std::string& keyboard) {
		this->keyboard = keyboard;
	}
	void setDisplay(const std::string& display) {
		this->display = display;
	}
	void setHost(const std::string& host) {
		this->host = host;
	}
	void showInfo() {
		std::cout << "电脑信息: \n";
		std::cout << cpu << " " << ram << " " << mouse << " " << keyboard << " " << display << " " << host << '\n';
	}
protected:
	std::string cpu, ram, mouse, keyboard, display, host;
};


//抽象建造者：创建某个品牌的电脑， 并且需要具有一个返回当前产品的方法
class AbstractComputerBuilder {
public:
	AbstractComputerBuilder(const std::string& cpu, const std::string& ram)
		:computer(new Computer(cpu, ram)) {}
	virtual ~AbstractComputerBuilder() {}
	virtual void setMouse() = 0;
	virtual void setKeyboard() = 0;
	virtual void setDisplay() = 0;
	virtual void setHost() = 0; 

	Computer* getProduct() {
		return computer;
	}
protected:
	Computer* computer;
};


//2. 具体建造者: 建造苹果电脑
class MacComputerBuilder :public AbstractComputerBuilder {
public:
	using AbstractComputerBuilder::AbstractComputerBuilder;
	~MacComputerBuilder() {
		if (computer) {
			delete computer;
			computer = nullptr;
		}
	}
	void setMouse() {
		computer->setMouse("苹果鼠标");
	}
	void setKeyboard() {
		computer->setKeyboard("苹果键盘");
	}
	void setDisplay() {
		computer->setDisplay("苹果显示器");
	}
	void setHost() {
		computer->setHost("苹果主机");
	}
};

//2. 具体建造者: 建造联想电脑 
class LenovoComputerBuilder :public AbstractComputerBuilder {
public:
	using AbstractComputerBuilder::AbstractComputerBuilder;
	~LenovoComputerBuilder() {
		if (computer) {
			delete computer;
			computer = nullptr;
		}
	}
	void setMouse() {
		computer->setMouse("联想鼠标");
	}
	void setKeyboard() {
		computer->setKeyboard("联想键盘");
	}
	void setDisplay() {
		computer->setDisplay("联想显示器");
	}
	void setHost() {
		computer->setHost("联想主机");
	}
};

//5. 指挥者
class Director {
public:
	Director() {}
	Computer* createProduct(AbstractComputerBuilder* computer_worker){
		//const std::string& mouse= "普通鼠标",
		//const std::string& display="普通显示器",
		//const std::string& keyboard="普通键盘",
		//const std::string& host="普通主机"
		computer_worker->setMouse();
		computer_worker->setDisplay();
		computer_worker->setKeyboard();
		computer_worker->setHost();
		//建造完成后返回产品
		return computer_worker->getProduct();
	}
};
int main() {
	//use smart pointer
	/*std::unique_ptr<AbstractComputerBuilder> builder(new LenovoComputerBuilder("I5处理器", "lemovoRam"));
	std::unique_ptr<Director> dmain(new Director);
	dmain->createProduct(builder.get())->showInfo();

	builder.reset(new MacComputerBuilder("I7处理器", "海力士222"));
	Computer* mac = dmain->createProduct(builder.get());
	mac->showInfo();*/

	AbstractComputerBuilder* builder = new LenovoComputerBuilder("I5处理器", "lemovoRam");
	Director* director = new Director();
	Computer* mac = director->createProduct(builder);
	mac->showInfo();

	delete builder;
	builder = nullptr;
	delete director;
	director = nullptr;
	return 0;
}


//方式二：

//#include <iostream>
//#include <string>
//#include <vector>
//#include <vld.h>
//
////具体产品：电脑
//class Computer {
//public:
//	Computer(const std::string& cpu, const std::string& ram) {
//		this->cpu = cpu;
//		this->ram = ram;
//	}
//	~Computer() {}
//	void setMouse(const std::string& mouse) {
//		this->mouse = mouse;
//	}
//	void setKeyboard(const std::string& keyboard) {
//		this->keyboard = keyboard;
//	}
//	void setDisplay(const std::string& display) {
//		this->display = display;
//	}
//	void setHost(const std::string& host) {
//		this->host = host;
//	}
//	void showInfo() {
//		std::cout << "电脑信息: \n";
//		std::cout << cpu << " " << ram << " " << mouse << " " << keyboard << " " << display << " " << host << '\n';
//	}
//protected:
//	std::string cpu, ram, mouse, keyboard, display, host;
//};
//
//
////抽象建造者：创建某个品牌的电脑， 并且需要具有一个返回当前产品的方法
//class AbstractComputerBuilder {
//public:
//	virtual ~AbstractComputerBuilder() {}
//	virtual void setMouse() = 0;
//	virtual void setKeyboard() = 0;
//	virtual void setDisplay() = 0;
//	virtual void setHost() = 0;
//
//	virtual Computer* getProduct() = 0;
//};
//
//
////2. 具体建造者: 建造苹果电脑
//class MacComputerBuilder :public AbstractComputerBuilder {
//public:
//	MacComputerBuilder(const std::string& cpu, const std::string& ram) {
//		computer = new Computer(cpu, ram);
//	}
//	~MacComputerBuilder() {
//		if (computer) {
//			delete computer;
//			computer = nullptr;
//		}
//	}
//	void setMouse() {
//		computer->setMouse("苹果鼠标");
//	}
//	void setKeyboard() {
//		computer->setKeyboard("苹果键盘");
//	}
//	void setDisplay() {
//		computer->setDisplay("苹果显示器");
//	}
//	void setHost() {
//		computer->setHost("苹果主机");
//	}
//
//	Computer* getProduct() {
//		return computer;
//	}
//private:
//	Computer* computer = nullptr;
//};
//
////2. 具体建造者: 建造联想电脑 
//class LenovoComputerBuilder :public AbstractComputerBuilder {
//public:
//	LenovoComputerBuilder(const std::string& cpu, const std::string& ram) {
//		computer = new Computer(cpu, ram);
//	}
//	~LenovoComputerBuilder() {
//		if (computer) {
//			delete computer;
//			computer = nullptr;
//		}
//	}
//	void setMouse() {
//		computer->setMouse("联想鼠标");
//	}
//	void setKeyboard() {
//		computer->setKeyboard("联想键盘");
//	}
//	void setDisplay() {
//		computer->setDisplay("联想显示器");
//	}
//	void setHost() {
//		computer->setHost("联想主机");
//	}
//	Computer* getProduct() {
//		return computer;
//	}
//private:
//	Computer* computer = nullptr;
//};
//
////5. 指挥者
//class Director {
//public:
//	Director() {}
//	Computer* createProduct(AbstractComputerBuilder* computer_worker) {
//		//const std::string& mouse= "普通鼠标",
//		//const std::string& display="普通显示器",
//		//const std::string& keyboard="普通键盘",
//		//const std::string& host="普通主机"
//		computer_worker->setMouse();
//		computer_worker->setDisplay();
//		computer_worker->setKeyboard();
//		computer_worker->setHost();
//		//建造完成后返回产品
//		return computer_worker->getProduct();
//	}
//};
//int main() {
//	//use smart pointer
//	std::unique_ptr<AbstractComputerBuilder> builder(new LenovoComputerBuilder("I5处理器", "lemovoRam"));
//	std::unique_ptr<Director> dmain(new Director);
//	dmain->createProduct(builder.get())->showInfo();
//
//	builder.reset(new MacComputerBuilder("I7处理器", "海力士222"));
//	Computer* mac = dmain->createProduct(builder.get());
//	mac->showInfo();
//
//	return 0;
//}