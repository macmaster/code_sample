#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <algorithm>

void parseSource(std::vector<std::string> source,
				 std::unordered_map<std::string, std::string> &attributes);
void parseQueries(std::vector<std::string> source,
				  std::unordered_map<std::string, std::string> &attributes);
int main() {
    // input source
    int lineCount = 0, queryCount = 0;
    std::vector<std::string> lines, queries;
	std::unordered_map<std::string, std::string> attributes;

    // read source and queries
    std::cin >> lineCount >> queryCount;
	std::cin.ignore(256, '\n');
    for(int i = 0; i < lineCount + queryCount; i++) {
        std::string line;
        std::getline(std::cin, line);
		if(i < lineCount){
        	lines.push_back(line);
		} else{
			queries.push_back(line);
		}
    }

	// parse source code
	parseSource(lines, attributes);
	//for(auto& attr : attributes){
	//	std::cout << "key: " << attr.first << std::endl;
	//	std::cout << "value:  " << attr.second << std::endl;
	//}
		

	// parse HRML queries
	parseQueries(queries, attributes);

}


void parseSource(std::vector<std::string> lines, 
	std::unordered_map<std::string, std::string> &attributes){
	// parse attributes from source
	for(int i = 0; i < lines.size(); i++){
		// tokenize source line
		static std::string position = "";
		std::string line = lines.at(i);	
		std::istringstream iss(line);
		std::vector<std::string> tokens{
			std::istream_iterator<std::string>{iss},
			std::istream_iterator<std::string>{}
		};

		// printing tokens
		// std::cout << "tokens: " << i << std::endl;
		// for(std::string &token : tokens){
		//	std::cout << token << std::endl;
		// }
		
		// parse tag attributes
		std::string tag = tokens.at(0);
		int tagp, taglen, poslen = position.length();
		if((tagp = tag.find("</")) != std::string::npos){
			// end tag
			tag = tag.substr(tagp + 2, tag.find(">") - 1);
			taglen = tag.length();
			position.erase(poslen - taglen, taglen);
		} else if((tagp = tag.find("<")) != std::string::npos){
			// start tag
			tag = tag.substr(tagp + 1, tag.find(">") - 1);
			position += "." + tag;
		} else{
			continue; // missing source tag
		} //std::cout << position << std::endl;

		int jdx = 1;
		bool parseName = true;
		std::string name, value;
		while(jdx < tokens.size()){
			std::string token = tokens.at(jdx);
			int epos = token.find("=");
			if(parseName && epos != 0){
				if(epos != std::string::npos){
					// contains equals
					name = token.substr(0, epos);
					parseName = false;
					if(epos != (token.length() - 1)){
						// contains value too
						parseName = true;
						value = token.substr(epos, std::string::npos);
						int firstQ = value.find_first_of("\"");
						int lastQ = value.find_last_of("\"");
						value = value.substr(firstQ + 1, lastQ - firstQ - 1); 
						attributes[position+"~"+name] = value;
					} 
				} else{
					name = token;
					parseName = false;
				}
			} else if(!parseName && epos != (token.length() - 1)){
				parseName = true;
				value = token;
				if(epos != std::string::npos){
					value = token.substr(epos, std::string::npos);
				}
				int firstQ = value.find_first_of("\"");
				int lastQ = value.find_last_of("\"");
				value = value.substr(firstQ + 1, lastQ - firstQ - 1); 
				attributes[position+"~"+name] = value;
			} jdx++;
		}
	}

}

void parseQueries(std::vector<std::string> queries, 
	std::unordered_map<std::string, std::string> &attributes){
	// parse queries from query list
	for(std::string query : queries){
		std::string key = "." + query;
		auto attr = attributes.find(key);
		if(attr != attributes.end()){
			std::cout << attr->second << std::endl;
		} else{
			std::cout << "Not Found!" << std::endl;
		}
	}
}

