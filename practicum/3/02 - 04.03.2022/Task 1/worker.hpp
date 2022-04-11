#ifndef __WORKER_HPP
#define __WORKER_HPP

class Worker {
  private:
    char *name = nullptr;
    double salary;
    Worker *boss;

  public:
    Worker();
    Worker(const char *name, double salary, Worker *boss);
    Worker(const Worker &o);
    ~Worker();

    const char *getName() const;

    void setName(const char *name);

    void printCEO() const;

    Worker &operator=(const Worker &o);
};

#endif // __WORKER_HPP
