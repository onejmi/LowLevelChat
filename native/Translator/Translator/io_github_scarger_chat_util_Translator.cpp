#include "io_github_scarger_chat_util_Translator.h"
#include <string.h>
#include <cstdint>
#include <deque>
#include <list>
#include <limits>



namespace scarger {
	typedef struct InsertableQueue {
	private:
		std::deque<std::string>* innerDeque = new std::deque<std::string>();
	public:
		void push(const std::string &message) {
			innerDeque->push_back(message);
		}

		void pop() {
			innerDeque->pop_front();
		}

		std::deque<std::string>* inner() {
			return innerDeque;
		}
		~InsertableQueue() {
			//clean memory off heap (safely)
			std::deque<std::string>().swap(*innerDeque);
			delete innerDeque;
		}
	} queue;
}

//local to this translation unit
static struct MessageRegistry {
private:
	//heap allocate queue+list for use through process lifetime 
	scarger::queue* queue;
	const int MAX_SIZE;
public:
	MessageRegistry(int maximumSize) : MAX_SIZE(maximumSize) {
		queue = new scarger::queue;
	}
	int push(std::string const& message) {
		unsigned short currLength = queue->inner()->size();
		if (currLength >= MAX_SIZE) {
			//replace one of the (old) first 90 entries
			unsigned int randomIndex = std::rand() % 90;
			//queue->pop();
			auto iteratorIndex = queue->inner()->begin() + randomIndex;
			//underlying.erase(queue->_Get_container.begin());
			queue->inner()->insert(iteratorIndex, message);
			return randomIndex;
		}
		queue->push(message);
		return currLength;
	}

	std::string get(int messageId) {
		if (messageId > -1 && messageId < queue->inner()->size()) {
			std::deque<std::string>* underlyingDeque = queue->inner();
			return (*underlyingDeque)[messageId];
		}
		return "Invalid ID";
	}

	unsigned short size() {
		return (queue->inner()->size());
	}

	~MessageRegistry() {
		queue->~InsertableQueue();
	}
} MESSAGES(100);

/*
* Class:     io_github_scarger_chat_util_Translator
* Method:    encrypt
* Signature: (Ljava/lang/String;)I
*/
JNIEXPORT jint JNICALL Java_io_github_scarger_chat_util_Translator_encrypt
(JNIEnv* env, jobject instance, jstring message) {
	unsigned int nextIndex = MESSAGES.push(env->GetStringUTFChars(message, 0));
	return nextIndex;
}

/*
* Class:     io_github_scarger_chat_util_Translator
* Method:    translate
* Signature: (I)Ljava/lang/String;
*/
JNIEXPORT jstring JNICALL Java_io_github_scarger_chat_util_Translator_translate
(JNIEnv* env, jobject instance, jint messageID) {
	if (((int)messageID) > -1) {
		return env->NewStringUTF(MESSAGES.get(messageID).c_str());
	}
	return (jstring) "Invalid";
}

/*
* Class:     io_github_scarger_chat_util_dispose
* Method:    dispose
* Signature: ()V
*/
JNIEXPORT void JNICALL Java_io_github_scarger_chat_util_Translator_dispose
(JNIEnv* env, jobject instance) {
	//deconstruct registry + safely deallocate underlying queue
	MESSAGES.~MessageRegistry();
}
