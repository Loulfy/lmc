#include <iostream>
#include <jni.h>
#include <vector>

int main()
{
    JavaVM *jvm;       /* denotes a Java VM */
    JNIEnv *env;       /* pointer to native method interface */

    auto options = new JavaVMOption[12];
    options[0].optionString = const_cast<char *>("-Xmx7G");
    options[1].optionString = const_cast<char *>("-XX:+UseConcMarkSweepGC");
    options[2].optionString = const_cast<char *>("-XX:+CMSIncrementalMode");
    options[3].optionString = const_cast<char *>("-XX:-UseAdaptiveSizePolicy");
    options[4].optionString = const_cast<char *>("-Xmn4G");
    options[5].optionString = const_cast<char *>("-Djava.library.path=/home/loulfy/ATLauncher/Instances/DNSTechpack/bin/natives/");
    options[6].optionString = const_cast<char *>("-Djava.class.path=/home/loulfy/Instances/DNSTechpack/jarmods/forge-1.12.2-14.23.1.2555-universal.jar:/home/loulfy/Instances/DNSTechpack/jarmods/dnsTitleLogo-v2.zip:/home/loulfy/Instances/DNSTechpack/bin/launchwrapper-1.12.jar:/home/loulfy/Instances/DNSTechpack/bin/asm-all-5.2.jar:/home/loulfy/Instances/DNSTechpack/bin/jline-2.13.jar:/home/loulfy/Instances/DNSTechpack/bin/akka-actor_2.11-2.3.3.jar:/home/loulfy/Instances/DNSTechpack/bin/config-1.2.1.jar:/home/loulfy/Instances/DNSTechpack/bin/scala-actors-migration_2.11-1.1.0.jar:/home/loulfy/Instances/DNSTechpack/bin/scala-compiler-2.11.1.jar:/home/loulfy/Instances/DNSTechpack/bin/scala-continuations-library_2.11-1.0.2.jar:/home/loulfy/Instances/DNSTechpack/bin/scala-continuations-plugin_2.11.1-1.0.2.jar:/home/loulfy/Instances/DNSTechpack/bin/scala-library-2.11.1.jar:/home/loulfy/Instances/DNSTechpack/bin/scala-parser-combinators_2.11-1.0.1.jar:/home/loulfy/Instances/DNSTechpack/bin/scala-reflect-2.11.1.jar:/home/loulfy/Instances/DNSTechpack/bin/scala-swing_2.11-1.0.1.jar:/home/loulfy/Instances/DNSTechpack/bin/scala-xml_2.11-1.0.2.jar:/home/loulfy/Instances/DNSTechpack/bin/lzma-0.0.1.jar:/home/loulfy/Instances/DNSTechpack/bin/jopt-simple-5.0.3.jar:/home/loulfy/Instances/DNSTechpack/bin/vecmath-1.5.2.jar:/home/loulfy/Instances/DNSTechpack/bin/trove4j-3.0.3.jar:/home/loulfy/Instances/DNSTechpack/bin/patchy-1.1.jar:/home/loulfy/Instances/DNSTechpack/bin/oshi-core-1.1.jar:/home/loulfy/Instances/DNSTechpack/bin/jna-4.4.0.jar:/home/loulfy/Instances/DNSTechpack/bin/platform-3.4.0.jar:/home/loulfy/Instances/DNSTechpack/bin/icu4j-core-mojang-51.2.jar:/home/loulfy/Instances/DNSTechpack/bin/codecjorbis-20101023.jar:/home/loulfy/Instances/DNSTechpack/bin/codecwav-20101023.jar:/home/loulfy/Instances/DNSTechpack/bin/libraryjavasound-20101123.jar:/home/loulfy/Instances/DNSTechpack/bin/librarylwjglopenal-20100824.jar:/home/loulfy/Instances/DNSTechpack/bin/soundsystem-20120107.jar:/home/loulfy/Instances/DNSTechpack/bin/netty-all-4.1.9.Final.jar:/home/loulfy/Instances/DNSTechpack/bin/guava-21.0.jar:/home/loulfy/Instances/DNSTechpack/bin/commons-lang3-3.5.jar:/home/loulfy/Instances/DNSTechpack/bin/commons-io-2.5.jar:/home/loulfy/Instances/DNSTechpack/bin/commons-codec-1.10.jar:/home/loulfy/Instances/DNSTechpack/bin/jinput-2.0.5.jar:/home/loulfy/Instances/DNSTechpack/bin/jutils-1.0.0.jar:/home/loulfy/Instances/DNSTechpack/bin/gson-2.8.0.jar:/home/loulfy/Instances/DNSTechpack/bin/authlib-1.5.25.jar:/home/loulfy/Instances/DNSTechpack/bin/realms-1.10.17.jar:/home/loulfy/Instances/DNSTechpack/bin/commons-compress-1.8.1.jar:/home/loulfy/Instances/DNSTechpack/bin/httpclient-4.3.3.jar:/home/loulfy/Instances/DNSTechpack/bin/commons-logging-1.1.3.jar:/home/loulfy/Instances/DNSTechpack/bin/httpcore-4.3.2.jar:/home/loulfy/Instances/DNSTechpack/bin/fastutil-7.1.0.jar:/home/loulfy/Instances/DNSTechpack/bin/log4j-api-2.8.1.jar:/home/loulfy/Instances/DNSTechpack/bin/log4j-core-2.8.1.jar:/home/loulfy/Instances/DNSTechpack/bin/lwjgl-2.9.4-nightly-20150209.jar:/home/loulfy/Instances/DNSTechpack/bin/lwjgl_util-2.9.4-nightly-20150209.jar:/home/loulfy/Instances/DNSTechpack/bin/text2speech-1.10.3.jar:/home/loulfy/Instances/DNSTechpack/bin/minecraft.jar");
    options[7].optionString = const_cast<char *>("-XX:MetaspaceSize=1024M");
    options[8].optionString = const_cast<char *>("-XX:-OmitStackTraceInFastThrow");

    JavaVMInitArgs vm_args{};
    vm_args.version = JNI_VERSION_1_8;
    vm_args.nOptions = 9;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = JNI_FALSE;
    //JNI_GetDefaultJavaVMInitArgs(&vm_args);

    JNI_CreateJavaVM(&jvm, reinterpret_cast<void**>(&env), &vm_args);
    jclass cls = env->FindClass("net/minecraft/launchwrapper/Launch");

    std::vector<std::string> params;
    params.emplace_back("--tweakClass=net.minecraftforge.fml.common.launcher.FMLTweaker");
    params.emplace_back("--accessToken");
    params.emplace_back("123456789");
    auto arr = env->NewObjectArray(static_cast<jsize>(params.size()), env->FindClass("java/lang/String"), env->NewStringUTF(""));
    for(int i=0; i < params.size(); i++)
        env->SetObjectArrayElement(arr,i,env->NewStringUTF(params[i].c_str()));

    if(cls == nullptr) throw std::runtime_error("CLASS NOT FOUND");

    jmethodID MainMethod = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
    env->CallStaticVoidMethod(cls, MainMethod, arr);

    if (env->ExceptionOccurred()) {
        env->ExceptionDescribe();
    }

    jvm->DestroyJavaVM();

    return 0;
}