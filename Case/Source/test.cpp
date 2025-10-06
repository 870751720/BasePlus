#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace pt = boost::property_tree;

// �������õ� XML �ļ�
void save_config(const std::string& filename) {
	pt::ptree tree;

	// �����������
	tree.put("config.app_name", "MyApplication");
	tree.put("config.version", "1.0.0");
	tree.put("config.window.width", 800);
	tree.put("config.window.height", 600);
	tree.put("config.window.fullscreen", false);

	// ���һ���б�
	pt::ptree& plugins = tree.add("config.plugins", "");
	pt::ptree plugin1, plugin2;
	plugin1.put("", "network");
	plugin2.put("", "graphics");
	plugins.push_back(std::make_pair("", plugin1));
	plugins.push_back(std::make_pair("", plugin2));

	// д�� XML �ļ�
	try {
		pt::write_xml(filename, tree, std::locale(),
			pt::xml_writer_make_settings<std::string>(' ', 4));
		std::cout << "�����ѱ��浽 " << filename << std::endl;
	}
	catch (const pt::xml_parser_error& e) {
		std::cerr << "д�� XML ����: " << e.what() << std::endl;
	}
}

// �� XML �ļ���ȡ����
void load_config(const std::string& filename) {
	pt::ptree tree;

	try {
		// ��ȡ XML �ļ�
		pt::read_xml(filename, tree);

		// ��ȡ��������
		std::cout << "\n��ȡ����:" << std::endl;
		std::cout << "Ӧ������: " << tree.get<std::string>("config.app_name") << std::endl;
		std::cout << "�汾��: " << tree.get<std::string>("config.version") << std::endl;

		// ��ȡ��������
		std::cout << "\n��������:" << std::endl;
		std::cout << "���: " << tree.get<int>("config.window.width") << std::endl;
		std::cout << "�߶�: " << tree.get<int>("config.window.height") << std::endl;
		std::cout << "ȫ��ģʽ: " << std::boolalpha
			<< tree.get<bool>("config.window.fullscreen") << std::endl;

		// ��ȡ����б�
		std::cout << "\n����б�:" << std::endl;
		for (const auto& plugin : tree.get_child("config.plugins")) {
			std::cout << "- " << plugin.second.data() << std::endl;
		}

	}
	catch (const pt::xml_parser_error& e) {
		std::cerr << "��ȡ XML ����: " << e.what() << std::endl;
	}
	catch (const pt::ptree_error& e) {
		std::cerr << "���ö�ȡ����: " << e.what() << std::endl;
	}
}

// �޸�����
void modify_config(const std::string& filename) {
	pt::ptree tree;

	try {
		// ��ȡ��������
		pt::read_xml(filename, tree);

		// �޸Ĳ�������
		tree.put("config.version", "1.0.1");
		tree.put("config.window.width", 1024);
		tree.put("config.window.height", 768);

		// ���������
		tree.put("config.log_level", "info");

		// �����޸�
		pt::write_xml(filename, tree, std::locale(),
			pt::xml_writer_make_settings<std::string>(' ', 4));
		std::cout << "\n�����Ѹ���" << std::endl;

	}
	catch (const pt::ptree_error& e) {
		std::cerr << "�޸����ô���: " << e.what() << std::endl;
	}
}

int main() {
	const std::string config_file = "config.xml";

	// �����ʼ����
	save_config(config_file);

	// ��ȡ����
	load_config(config_file);

	// �޸�����
	modify_config(config_file);

	// �ٴζ�ȡ����ʾ�޸Ľ��
	load_config(config_file);

	return 0;
}