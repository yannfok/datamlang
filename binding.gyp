{
  "targets": [
    {
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ],
      "target_name": "DTMLTranspiler",
      "sources": [
        "./src/Transpiler.cc",
        "./src/Alias.cc",
        "./src/Aliases.cc",
        "./src/Error.cc",
        "./src/Function.cc",
        "./src/KeyWord.cc",
        "./src/Loop.cc",
        "./src/Parser.cc",
        "./src/StringUtils.cc",
      ],
       'cflags!': [ '-fno-exceptions' ],
       'cflags_cc!': [ '-fno-exceptions' ],
       'conditions': [
          ['OS=="mac"', {
                'xcode_settings': {
                  'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
                }
             }
          ]
       ]
    }
  ]
}