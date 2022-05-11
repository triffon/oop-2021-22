#ifndef __AI_HPP
#define __AI_HPP

#include <iostream>

class AI {
    char* algorithm;
    double threshold;

    void setAlgorithm(char const* _algorithm);
public:

    AI(char const* _algorithm = "<неизвестен>", double _threshold = 0);
    AI(AI const& other);
    AI& operator=(AI const& other);
    ~AI();

    char const* getAlgorithm() const { return algorithm; }
    double getThreshold() const { return threshold; }

    void print(std::ostream& os = std::cout) const;

    void setThreshold(double _threshold) { threshold = _threshold; }
};

#endif