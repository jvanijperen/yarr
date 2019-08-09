#ifndef USERINTERACTOR_H_
#define USERINTERACTOR_H_

class UserInteractor {
public:
	UserInteractor();
	virtual ~UserInteractor();

	void run();

private:
	void run_loop();
};

#endif /* USERINTERACTOR_H_ */
