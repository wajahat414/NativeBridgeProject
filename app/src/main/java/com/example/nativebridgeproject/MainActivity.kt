package com.example.nativebridgeproject

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import com.example.nativebridgeproject.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        val nativeLibraryDir = application.applicationContext.applicationInfo.nativeLibraryDir
        Log.w("Kotlin", "Native library directory: $nativeLibraryDir")

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
//        binding.sampleText.text = stringFromJNI()

        val childLibPath = "libchild_lib.so"

        val nativeInterface = NativeInterface()
//        binding.sampleText.text = nativeInterface.loadChildLibrary("$childLibPath")

// Specify the path to the child library .so file

    }

    /**
     * A native method that is implemented by the 'nativebridgeproject' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'nativebridgeproject' library on application startup.
        init {
            System.loadLibrary("nativebridgeproject")
            System.loadLibrary("parent_lib")
            System.loadLibrary("child_lib")
        }
    }
}