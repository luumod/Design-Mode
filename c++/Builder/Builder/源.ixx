#include <iostream>
#include <string>
#include <vector>
#include <vld.h>
/*
* 抽象产品
具体产品电脑：鼠标，键盘，显示器，主机

*/

//1. 抽象产品类
class AbstractProduct {
public:
	virtual ~AbstractProduct() {}
	virtual void setMouse(const std::string& mouse) = 0;
	virtual void setKeyboard(const std::string& keyboard) = 0;
	virtual void setDisplay(const std::string& display) = 0;
	virtual void setHost(const std::string& host) = 0;
	virtual void showInfo() = 0;
};
//2. 具体产品
class Computer :public AbstractProduct {
public:
	virtual ~Computer() {}
	void setMouse(const std::string& mouse) {
		m_vec.push_back(mouse);
	}
	void setKeyboard(const std::string& keyboard) {
		m_vec.push_back(keyboard);
	}
	void setDisplay(const std::string& display) {
		m_vec.push_back(display);
	}
	void setHost(const std::string& host) {
		m_vec.push_back(host);
	}
	void showInfo() {
		std::cout << "电脑组装信息: \n";
		for (auto& x : m_vec) {
			std::cout << x << ' ';
		}
		std::cout << '\n';
	}
protected:
	std::vector<std::string> m_vec;
};

//3. 抽象建造者
class AbstractBuilder {
public:
	AbstractBuilder() :m_pro(new Computer) {}
	//抽象建造过程
	virtual void buildMouse(const std::string& mouse) = 0;
	virtual void buildKeyboard(const std::string& keyboard) = 0;
	virtual void buildDisplay(const std::string& display) = 0;
	virtual void buildHost(const std::string& host) = 0;
	//用于指挥者返回建造产品
	AbstractProduct* product() {
		return m_pro;
	}
protected:
	AbstractProduct* m_pro = nullptr;
};

//4. 具体建造者
class Worker :public AbstractBuilder {
public:
	void buildMouse(const std::string& mouse)override {
		m_pro->setMouse(mouse);
	}
	void buildKeyboard(const std::string& keyboard)override {
		m_pro->setKeyboard(keyboard);
	}
	void buildDisplay(const std::string& display)override {
		m_pro->setDisplay(display);
	}
	void buildHost(const std::string& host)override {
		m_pro->setHost(host);
	}
};

//5. 指挥者
class Director {
public:
	Director(AbstractBuilder* worker)
		:m_worker(worker) {}
	AbstractProduct* createProduct(const std::string& mouse,
		const std::string& keyboard, 
		const std::string& display,
		const std::string& host) {
		m_worker->buildMouse(mouse);
		m_worker->buildKeyboard(keyboard);
		m_worker->buildDisplay(display);
		m_worker->buildHost(host);
		//建造完成后返回产品
		return m_worker->product();
	}
private:
	AbstractBuilder* m_worker = nullptr;
};
int main() {
	//创建抽象建造者
	std::unique_ptr<AbstractBuilder> builder(new Worker());
	//创建指挥者
	std::unique_ptr<Director> pD(new Director(builder.get()));
	//指挥者创建产品
	std::unique_ptr<AbstractProduct> pro(pD->createProduct("雷蛇鼠标", "罗技键盘",
		"联想显示器", "外星人主机"));
	pro->showInfo();
	
	return 0;
}