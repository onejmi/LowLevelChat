/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class io_github_scarger_chat_util_Translator */

#ifndef _Included_io_github_scarger_chat_util_Translator
#define _Included_io_github_scarger_chat_util_Translator
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     io_github_scarger_chat_util_Translator
 * Method:    encrypt
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_io_github_scarger_chat_util_Translator_encrypt
  (JNIEnv *, jobject, jstring);

/*
 * Class:     io_github_scarger_chat_util_Translator
 * Method:    translate
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_io_github_scarger_chat_util_Translator_translate
  (JNIEnv *, jobject, jint);

/*
* Class:     io_github_scarger_chat_util_dispose
* Method:    translate
* Signature: ()V
*/
JNIEXPORT void JNICALL Java_io_github_scarger_chat_util_Translator_dispose
(JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif