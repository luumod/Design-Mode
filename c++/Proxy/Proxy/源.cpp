#include <iostream>
#include <string>
#include <vld.h>

//抽象产品类
class AbstractImage {
public:
	virtual ~AbstractImage() {}
	virtual void display() = 0;
};

//具体产品类
class Image : public AbstractImage {
public:
	Image(const std::string& filePath) :m_filePath(filePath) {
		loadImage(); //加载图片
	}
	~Image() {}
	void loadImage() {
		std::cout << "从磁盘路径加载图片: " << m_filePath << '\n';
	}
	void display()override {
		std::cout << "---显示图片---" << '\n';
	}
private:
	std::string m_filePath;
};
//代理类
class ProxyImage :public AbstractImage {
public:
	ProxyImage(const std::string& filePath) {
		if (image == nullptr) {
			image = new Image(filePath);
		}
	}
	~ProxyImage() {
		if (image) {
			delete image;
			image = nullptr;
		}
	}
	void display()override {
		image->display();
	}
private:
	Image* image = nullptr;
};
int main() {

	AbstractImage* image = new ProxyImage("D:\\asserts\\images");

	image->display();

	std::cout << '\n';
	image->display();

	std::cout << "\n";
	image->display();
	
	delete image;
	image = nullptr;

	return 0;
}