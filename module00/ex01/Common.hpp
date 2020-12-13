//
// Created by Johnette Nannie on 12/12/20.
//

#ifndef COMMON_HPP
# define COMMON_HPP

# include <string>

class Common {
public:
						Common();
						~Common();

	static std::string	getLineSafe(void);
};

#endif //COMMON_HPP
