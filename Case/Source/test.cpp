#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace pt = boost::property_tree;

// 保存配置到 XML 文件
void save_config(const std::string& filename) {
	pt::ptree tree;

	// 添加配置数据
	tree.put("config.app_name", "MyApplication");
	tree.put("config.version", "1.0.0");
	tree.put("config.window.width", 800);
	tree.put("config.window.height", 600);
	tree.put("config.window.fullscreen", false);

	// 添加一个列表
	pt::ptree& plugins = tree.add("config.plugins", "");
	pt::ptree plugin1, plugin2;
	plugin1.put("", "network");
	plugin2.put("", "graphics");
	plugins.push_back(std::make_pair("", plugin1));
	plugins.push_back(std::make_pair("", plugin2));

	// 写入 XML 文件
	try {
		pt::write_xml(filename, tree, std::locale(),
			pt::xml_writer_make_settings<std::string>(' ', 4));
		std::cout << "配置已保存到 " << filename << std::endl;
	}
	catch (const pt::xml_parser_error& e) {
		std::cerr << "写入 XML 错误: " << e.what() << std::endl;
	}
}

// 从 XML 文件读取配置
void load_config(const std::string& filename) {
	pt::ptree tree;

	try {
		// 读取 XML 文件
		pt::read_xml(filename, tree);

		// 读取基本配置
		std::cout << "\n读取配置:" << std::endl;
		std::cout << "应用名称: " << tree.get<std::string>("config.app_name") << std::endl;
		std::cout << "版本号: " << tree.get<std::string>("config.version") << std::endl;

		// 读取窗口配置
		std::cout << "\n窗口配置:" << std::endl;
		std::cout << "宽度: " << tree.get<int>("config.window.width") << std::endl;
		std::cout << "高度: " << tree.get<int>("config.window.height") << std::endl;
		std::cout << "全屏模式: " << std::boolalpha
			<< tree.get<bool>("config.window.fullscreen") << std::endl;

		// 读取插件列表
		std::cout << "\n插件列表:" << std::endl;
		for (const auto& plugin : tree.get_child("config.plugins")) {
			std::cout << "- " << plugin.second.data() << std::endl;
		}

	}
	catch (const pt::xml_parser_error& e) {
		std::cerr << "读取 XML 错误: " << e.what() << std::endl;
	}
	catch (const pt::ptree_error& e) {
		std::cerr << "配置读取错误: " << e.what() << std::endl;
	}
}

// 修改配置
void modify_config(const std::string& filename) {
	pt::ptree tree;

	try {
		// 读取现有配置
		pt::read_xml(filename, tree);

		// 修改部分配置
		tree.put("config.version", "1.0.1");
		tree.put("config.window.width", 1024);
		tree.put("config.window.height", 768);

		// 添加新配置
		tree.put("config.log_level", "info");

		// 保存修改
		pt::write_xml(filename, tree, std::locale(),
			pt::xml_writer_make_settings<std::string>(' ', 4));
		std::cout << "\n配置已更新" << std::endl;

	}
	catch (const pt::ptree_error& e) {
		std::cerr << "修改配置错误: " << e.what() << std::endl;
	}
}

int main() {
	const std::string config_file = "config.xml";

	// 保存初始配置
	save_config(config_file);

	// 读取配置
	load_config(config_file);

	// 修改配置
	modify_config(config_file);

	// 再次读取以显示修改结果
	load_config(config_file);

	return 0;
}