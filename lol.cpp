#include <iostream>
#include <jni.h>

int main()
{
    JavaVM *jvm;
    JNIEnv *env;

    auto options = new JavaVMOption[10];
    options[0].optionString = const_cast<char *>("-Xmx7G");
    options[1].optionString = const_cast<char *>("-XX:+UseConcMarkSweepGC");
    options[2].optionString = const_cast<char *>("-XX:+CMSIncrementalMode");
    options[3].optionString = const_cast<char *>("-XX:-UseAdaptiveSizePolicy");
    options[4].optionString = const_cast<char *>("-Xmn4G");
    options[5].optionString = const_cast<char *>("-Dminecraft.launcher.brand=java-minecraft-launcher");
    options[6].optionString = const_cast<char *>("-Dminecraft.launcher.version=1.6.84-j");
    options[7].optionString = const_cast<char *>("-Dminecraft.client.jar=/home/loulfy/.minecraft/versions/1.12.2/1.12.2.jar");
    options[8].optionString = const_cast<char *>("-Djava.library.path=/home/loulfy/ATLauncher/Instances/DNSTechpack/bin/natives/");
    options[9].optionString = const_cast<char *>("-Djava.class.path=/home/loulfy/Instances/DNSTechpack/jarmods/forge-1.12.2-14.23.1.2555-universal.jar:blalblalblal");
    options[10].optionString = const_cast<char *>("-XX:MetaspaceSize=1024M");
    options[11].optionString = const_cast<char *>("-XX:-OmitStackTraceInFastThrow");

    JavaVMInitArgs vm_args{};
    vm_args.version = JNI_VERSION_1_8;
    vm_args.nOptions = 11;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = JNI_FALSE;

    JNI_CreateJavaVM(&jvm, reinterpret_cast<void**>(&env), &vm_args);
    jclass cls = env->FindClass("net/minecraft/launchwrapper/Launch");

    if(cls == nullptr) throw std::runtime_error("CLASS NOT FOUND");

    jmethodID MainMethod = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
    env->CallStaticVoidMethod(cls, MainMethod, NULL);
    jvm->DestroyJavaVM();

    return 0;
}
