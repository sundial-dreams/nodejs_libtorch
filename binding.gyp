{
    "targets": [
        {
            "target_name": "torch_script",
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
                "libtorch/include"
             ],
              # 添加下面的依赖库，根据当前Node.js版本判断
            "dependencies": [
                "<!(node -p \"require('node-addon-api').gyp\")"
            ],
            "cflags!": ["-fno-exceptions", "-fno-rtti"],
            "cflags_cc!": ["-fno-exceptions", "-fno-rtti"],
            "cflags": ["-fexceptions", "-frtti"],
            "cflags_cc": ["-fexceptions", "-frtti"],
            "conditions": [
                 ['OS=="mac"', {    # 直接在xcode上打开异常捕获功能
                     'xcode_settings': {
                        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                        'GCC_ENABLE_CPP_RTTI': 'YES'
                 }
             }]
            ],
            'libraries': [
                '<!@(ls /Users/dengpengfei/Documents/Project/C++/Node-addon-libtorch/libtorch/lib)'
             ],
             'link_settings': {
               'library_dirs': [
                    '/Users/dengpengfei/Documents/Project/C++/Node-addon-libtorch/libtorch/lib'
               ]
             },
            "defines": [
                # "NAPI_DISABLE_CPP_EXCEPTIONS" # 记得加这个宏
            ],
            "sources": [
                "torch_script.cpp",
                "node_script.cpp",
            ]
        }
    ]
}

