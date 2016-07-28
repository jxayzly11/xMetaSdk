/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp;

import android.content.Intent;
import android.os.Bundle;
import com.metafun.metaads.MetaAds;
import com.metafun.metabase.MetaBase;
import com.metafun.metafacebook.MetaFacebook;
import com.metafun.metaplatform.MetaPlatform;
import com.metafun.metavideo.MetaVideo;
import org.cocos2dx.lib.Cocos2dxActivity;

public class AppActivity extends Cocos2dxActivity {
	@Override
    protected void onCreate(final Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		MetaBase.initMeta(this, this.mGLSurfaceView);
		MetaVideo.initMeta();
		MetaAds.initMeta();
		MetaPlatform.initMeta();
		MetaFacebook.initMeta(savedInstanceState);
	}

@Override
	protected void onSaveInstanceState(Bundle outState) {
		super.onSaveInstanceState(outState);
		MetaFacebook.onSaveInstanceState(outState);
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		MetaPlatform.onActivityResult(requestCode, resultCode, data);
		MetaFacebook.onActivityResult(requestCode, resultCode, data);
	}

	@Override
	public void onWindowFocusChanged(final boolean hasFocus) {
		super.onWindowFocusChanged(hasFocus);
		MetaPlatform.onWindowFocusChanged(hasFocus);
	}

	@Override
    protected void onResume() {
        super.onResume();
        MetaAds.onResume(this);
        MetaFacebook.onResume(this);
		MetaVideo.onResume(this);
    }

    @Override
    protected void onPause() {
    	super.onPause();
    	MetaAds.onResume(this);
    	MetaFacebook.onPause(this);
		MetaVideo.onPause(this);
    }

    @Override
	protected void onStart() {
    	super.onStart();
    	MetaPlatform.onStart();
	}

    @Override
	protected void onStop() {
		super.onStop();
		MetaPlatform.onStop();
	}

    @Override
    protected void onDestroy() {
    	super.onDestroy();
    	MetaAds.onDestroy(this);
    	MetaPlatform.onDestroy();
		MetaFacebook.onDestroy();
    }

    @Override
	public void onBackPressed() {
		MetaAds.onBackPressed();
	}
}

