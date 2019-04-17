
#include <voce.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

/// A sample application showing how to use Voce's speech synthesis 
/// capabilities.

int main(int argc, char **argv)
{
	voce::init("../../../lib", false, true, "./grammar", "digits");

	std::cout << "This is a speech recognition test. " 
		<< "Speak digits from 0-9 into the microphone. " 
		<< "Speak 'quit' to quit." << std::endl;

	bool quit = false;
	while (!quit)
	{
		// Normally, applications would do application-specific things 
		// here.  For this sample, we'll just sleep for a little bit.
#ifdef _WIN32
		::Sleep(200);
#else
		usleep(200);
#endif

		while (voce::getRecognizerQueueSize() > 0)
		{
			std::string s = voce::popRecognizedString();

			// Check if the string contains 'quit'.
			if (std::string::npos != s.rfind("quit"))
			{
				quit = true;
			}

			std::cout << "You said: " << s << std::endl;
			//voce::synthesize(s);
		}
	}

	voce::destroy();
	return 0;
}
