LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame 

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../../Classes/AppDelegate.cpp \
                   ../../../Classes/BulletLayer.cpp \
                   ../../../Classes/ControlLayer.cpp \
                   ../../../Classes/Enemy.cpp \
                   ../../../Classes/EnemyLayer.cpp \
                   ../../../Classes/GameLayer.cpp \
                   ../../../Classes/GameOverLayer.cpp \
                   ../../../Classes/GameOverScene.cpp \
                   ../../../Classes/GameScene.cpp \
                   ../../../Classes/MutiBulletsLayer.cpp \
                   ../../../Classes/NoTouchLayer.cpp \
                   ../../../Classes/PlaneLayer.cpp \
                   ../../../Classes/UFOLayer.cpp \
                   ../../../Classes/WelcomeLayer.cpp \
                   ../../../Classes/WelcomeScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
