package com.example.nativebridgeproject


    class NativeInterface {

        // Load the parent library
        init {

        }

        external fun loadChildLibrary(libPath: String): String
        external fun executeChildFunction() : String
        external fun loadAndCallChildLibrary(string: String): String
    }

