#include <iostream>
#include <string>
#include <vector>

/*
我要发布文章，但是文章从头写太麻烦了，我们可以从已经存在的文章模板中导入
	然后再简单修改即可，这样就省时省力
*/
//文章模板
class TemplateArticle {
public:
	virtual TemplateArticle* clone() = 0;
};

class Article :public TemplateArticle {
public:
	Article() {}
	~Article() {}
	Article(const Article& lhs) {
		content = lhs.content; //直接赋值
	}
	void load() {
		content.push_back("文章模板内容1....");
		content.push_back("文章模板内容2....");
		content.push_back("文章模板内容3....");
		content.push_back("文章模板内容4....");
	}
	void add(const std::string& newInfo) {
		content.push_back(newInfo);
	}
	Article* clone()override {
		return new Article(*this);
	}
	void showContent() {
		for (auto& x : content) {
			std::cout << x << '\n';
		}
		std::cout << '\n';
	}
protected:
	std::vector<std::string> content; //内容
};

int main() {
	std::unique_ptr<Article> originTemplate(new Article());
	originTemplate->load();
	originTemplate->showContent();

	//新写一篇文章: 模板复制过来
	Article* article2 = originTemplate->clone();
	article2->add("新的内容...");
	article2->showContent();

	//复制模板
	Article* article3 = originTemplate->clone();
	article3->add("新的内容1...");
	article3->add("新的内容2...");
	article3->showContent();



	return 0;
}