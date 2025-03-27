#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) 
		: question(question) {}
	
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);		
		if (guessNumber == question) {
			return { true, 3, 0 };
		}
		
		return { false,getStrikeCount(guessNumber),getBallCOunt(guessNumber)};
	}

	void assertIllegalArgument(const std::string& guessNumber)	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters");
		}
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}

	bool isDuplicatedNumber(const string& guessNumber)	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
			
	}
	int getStrikeCount(const string& guessNumber) {
		int strikeCount = 0;
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == question[i]) strikeCount++;
		}
		return strikeCount;
	}
	int getBallCOunt(const string& guesssNumber) {
		int ballcount = 0;
		for (int guessIdx = 0; guessIdx < 3; guessIdx++) {
			for (int questionIdx = 0; questionIdx < 3; questionIdx++) {
				if (guessIdx == questionIdx) continue;
				if (guesssNumber[guessIdx] != question[questionIdx]) continue;
				ballcount++;
			}
		}
		return ballcount;
	}

private:
	string question;
};