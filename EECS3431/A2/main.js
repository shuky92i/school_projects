
// Frame rate updates
var frameCount = 0;
var lastTimeFrameRateSeconds = 0; // The last time frame rate was update in seconds
var sheepLastLoc = vec3(0.0, 0.0, 0.0);

var currentTimeInSeconds = 0;
var canvas;
var gl;
var lastTexVal;

var changingVertexColorLocatio;

var currProg;
var program ;
var program2;

var near = -100;
var far = 100;

var texNamesArray = ["./textures/door.png", "./textures/grass.png",
                      "./textures/window.png", "./textures/stone.png",
                      "./textures/no_entry.png"];

var left = -6.0;
var right = 6.0;
var ytop =6.0;
var bottom = -6.0;

var currentActiveTextureI


var lightPosition2 = vec4(100.0, 100.0, 100.0, 1.0 );
var lightPosition = vec4(0.0, 0.0, 100.0, 1.0 );

var lightAmbient = vec4(0.2, 0.2, 0.2, 1.0 );
var lightDiffuse = vec4( 1.0, 1.0, 1.0, 1.0 );
var lightSpecular = vec4( 1.0, 1.0, 1.0, 1.0 );

var materialAmbient = vec4( 1.0, 0.0, 1.0, 1.0 );
var materialDiffuse = vec4( 1.0, 0.8, 0.0, 1.0 );
var materialSpecular = vec4( 0.4, 0.4, 0.4, 1.0 );
var materialShininess = 30.0;


var ambientColor, diffuseColor, specularColor;

var modelMatrix, viewMatrix ;
var modelViewMatrix, projectionMatrix, normalMatrix;
var modelViewMatrixLoc, projectionMatrixLoc, normalMatrixLoc;
var eye;
var at = vec3(0.0, 0.0, 0.0);
var up = vec3(0.0, 1.0, 0.0);

var RX = 0 ;
var RY = 0 ;
var RZ = 0 ;

var MS = [] ; // The modeling matrix stack
var TIME = 0.0 ; // Realtime
var TIME = 0.0 ; // Realtime
var resetTimerFlag = true ;
var animFlag = false ;
var prevTime = 0.0 ;
var useTextures = 1 ;

// ------------ Images for textures stuff --------------
var texSize = 64;

var image1 = new Array()
for (var i =0; i<texSize; i++)  image1[i] = new Array();
for (var i =0; i<texSize; i++)
for ( var j = 0; j < texSize; j++)
image1[i][j] = new Float32Array(4);
for (var i =0; i<texSize; i++) for (var j=0; j<texSize; j++) {
    var c = (((i & 0x8) == 0) ^ ((j & 0x8)  == 0));
    image1[i][j] = [c, c, c, 1];
}

// Convert floats to ubytes for texture

var image2 = new Uint8Array(4*texSize*texSize);

for ( var i = 0; i < texSize; i++ )
for ( var j = 0; j < texSize; j++ )
for(var k =0; k<4; k++)
image2[4*texSize*i+4*j+k] = 255*image1[i][j][k];


var textureArray = [] ;



function isLoaded(im) {
    if (im.complete) {
        console.log("loaded") ;
        return true ;
    }
    else {
        console.log("still not loaded!!!!") ;
        return false ;
    }
}

function loadFileTexture(tex, filename)
{
    tex.textureWebGL  = gl.createTexture();
    tex.image = new Image();
    tex.image.src = filename ;
    tex.isTextureReady = false ;
    tex.image.onload = function() { handleTextureLoaded(tex); }
    // The image is going to be loaded asyncronously (lazy) which could be
    // after the program continues to the next functions. OUCH!
}

function loadImageTexture(tex, image) {
    tex.textureWebGL  = gl.createTexture();
    tex.image = new Image();
    //tex.image.src = "CheckerBoard-from-Memory" ;

    gl.bindTexture( gl.TEXTURE_2D, tex.textureWebGL );
    //gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true);
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, texSize, texSize, 0,
                  gl.RGBA, gl.UNSIGNED_BYTE, image);
    gl.generateMipmap( gl.TEXTURE_2D );
    gl.texParameteri( gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER,
                     gl.NEAREST_MIPMAP_LINEAR );
    gl.texParameteri( gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST );
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.REPEAT); //Prevents s-coordinate wrapping (repeating)
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.REPEAT); //Prevents t-coordinate wrapping (repeating)
    gl.bindTexture(gl.TEXTURE_2D, null);

    tex.isTextureReady = true ;

}

function initTextures() {

    textureArray.push({}) ;
    loadFileTexture(textureArray[textureArray.length-1],texNamesArray[0]) ;

    textureArray.push({}) ;
    loadFileTexture(textureArray[textureArray.length-1],texNamesArray[1]) ;

    textureArray.push({}) ;
    loadFileTexture(textureArray[textureArray.length-1],texNamesArray[2]) ;

    textureArray.push({}) ;
    loadFileTexture(textureArray[textureArray.length-1],texNamesArray[3]) ;

    textureArray.push({}) ;
    loadFileTexture(textureArray[textureArray.length-1],texNamesArray[4]) ;
}

function shiftFocusToTex(texName) {
  if (texNamesArray[0] != texName) {

    // Find the location of desired texture to be switched to beginning of array
    var desLocation;
    for (var i = 0; i < texNamesArray.length; i++) {
      if (texNamesArray[i] = texName) {
        desLocation = i;
        break;
      }
    }

    // Seitch elements so that the fragment shader can grab the new updated first element
    loadFileTexture(textureArray[0],texName) ;
    loadFileTexture(textureArray[desLocation],tmp) ;

  }
}


function handleTextureLoaded(textureObj) {
    gl.bindTexture(gl.TEXTURE_2D, textureObj.textureWebGL);
	gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, true); // otherwise the image would be flipped upsdide down
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, textureObj.image);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR_MIPMAP_NEAREST);
    gl.generateMipmap(gl.TEXTURE_2D);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.REPEAT); //Prevents s-coordinate wrapping (repeating)
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.REPEAT); //Prevents t-coordinate wrapping (repeating)
    gl.bindTexture(gl.TEXTURE_2D, null);
    console.log(textureObj.image.src) ;

    textureObj.isTextureReady = true ;
}

//----------------------------------------------------------------

function setColor(c)
{
    ambientProduct = mult(lightAmbient, c);
    diffuseProduct = mult(lightDiffuse, c);
    specularProduct = mult(lightSpecular, materialSpecular);

    gl.uniform4fv( gl.getUniformLocation(currProg,
                                         "ambientProduct"),flatten(ambientProduct) );
    gl.uniform4fv( gl.getUniformLocation(currProg,
                                         "diffuseProduct"),flatten(diffuseProduct) );
    gl.uniform4fv( gl.getUniformLocation(currProg,
                                         "specularProduct"),flatten(specularProduct) );
    gl.uniform4fv( gl.getUniformLocation(currProg,
                                         "lightPosition"),flatten(lightPosition) );
    gl.uniform1f( gl.getUniformLocation(currProg,
                                        "shininess"),materialShininess );
}

function toggleTextures() {
    useTextures = 1 - useTextures ;
    gl.uniform1i( gl.getUniformLocation(program, "useTextures"), useTextures );
}

function waitForTextures1(tex) {
    setTimeout( function() {
    console.log("Waiting for: "+ tex.image.src) ;
    wtime = (new Date()).getTime() ;
    if( !tex.isTextureReady )
    {
        console.log(wtime + " not ready yet") ;
        waitForTextures1(tex) ;
    }
    else
    {
        console.log("ready to render") ;
        window.requestAnimFrame(render);
    }
               },5) ;

}

// Takes an array of textures and calls render if the textures are created
function waitForTextures(texs) {
    setTimeout( function() {
               var n = 0 ;
               for ( var i = 0 ; i < texs.length ; i++ )
               {
                    console.log("boo"+texs[i].image.src) ;
                    n = n+texs[i].isTextureReady ;
               }
               wtime = (new Date()).getTime() ;
               if( n != texs.length )
               {
               console.log(wtime + " not ready yet") ;
               waitForTextures(texs) ;
               }
               else
               {
               console.log("ready to render") ;
               window.requestAnimFrame(render);
               }
               },5) ;

}

function runDefaultShader() {
  currProg = program;
  gl.useProgram( currProg );

  // Load canonical objects and their attributes
  Cube.init(currProg);
  Cylinder.init(9,currProg);
  Cone.init(9,currProg) ;
  Sphere.init(36,currProg) ;

  gl.uniform1i( gl.getUniformLocation(currProg, "useTextures"), useTextures );

  // record the locations of the matrices that are used in the shaders
  modelViewMatrixLoc = gl.getUniformLocation( currProg, "modelViewMatrix" );
  normalMatrixLoc = gl.getUniformLocation( currProg, "normalMatrix" );
  projectionMatrixLoc = gl.getUniformLocation( currProg, "projectionMatrix" );

  // set a default material
  setColor(materialDiffuse) ;
}

function runVirtualScreenShader() {
  currProg = program2;
  gl.useProgram( currProg );



  gl.uniform1i( gl.getUniformLocation(currProg, "useTextures"), useTextures );

  // record the locations of the matrices that are used in the shaders
  modelViewMatrixLoc = gl.getUniformLocation( currProg, "modelViewMatrix" );
  normalMatrixLoc = gl.getUniformLocation( currProg, "normalMatrix" );
  projectionMatrixLoc = gl.getUniformLocation( currProg, "projectionMatrix" );

  // set a default material
  setColor(materialDiffuse) ;
}

window.onload = function init() {

    canvas = document.getElementById( "gl-canvas" );

    gl = WebGLUtils.setupWebGL( canvas );
    if ( !gl ) { alert( "WebGL isn't available" ); }

    gl.viewport( 0, 0, canvas.width, canvas.height );
    gl.clearColor( 0.53, 0.8, 0.92, 1.0 );

    gl.enable(gl.DEPTH_TEST);

    //
    //  Load shaders and initialize attribute buffers
    //
    program = initShaders( gl, "vertex-shader", "fragment-shader" );
    program2 = initShaders( gl, "vertex-shader", "fragment-shader-virtual-screen" );

    runDefaultShader() ;

    // set the callbacks for the UI elements
    document.getElementById("sliderXi").oninput = function() {
        RX = this.value ;
        window.requestAnimFrame(render);
    };
    document.getElementById("sliderYi").oninput = function() {
        RY = this.value;
        window.requestAnimFrame(render);
    };
    document.getElementById("sliderZi").oninput = function() {
        RZ =  this.value;
        window.requestAnimFrame(render);
    };

    document.getElementById("animToggleButton").onclick = function() {
        if( animFlag ) {
            animFlag = false;
        }
        else {
            animFlag = true  ;
            resetTimerFlag = true ;
            window.requestAnimFrame(render);
        }
    };

    document.getElementById("textureToggleButton").onclick = function() {
        toggleTextures() ;
        window.requestAnimFrame(render);
    };

    var controller = new CameraController(canvas);
    controller.onchange = function(xRot,yRot) {
        RX = xRot ;
        RY = yRot ;
        window.requestAnimFrame(render); };

    // load and initialize the textures
    initTextures() ;

    // Recursive wait for the textures to load
    waitForTextures(textureArray) ;
    //setTimeout (render, 100) ;

}

// Sets the modelview and normal matrix in the shaders
function setMV() {
    modelViewMatrix = mult(viewMatrix,modelMatrix) ;
    gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(modelViewMatrix) );
    normalMatrix = inverseTranspose(modelViewMatrix) ;
    gl.uniformMatrix4fv(normalMatrixLoc, false, flatten(normalMatrix) );
}

// Sets the projection, modelview and normal matrix in the shaders
function setAllMatrices() {
    gl.uniformMatrix4fv(projectionMatrixLoc, false, flatten(projectionMatrix) );
    setMV() ;
}

// Draws a 2x2x2 cube center at the origin
// Sets the modelview matrix and the normal matrix of the global program
function drawCube() {
    setMV() ;
    Cube.draw() ;
}

// Draws a sphere centered at the origin of radius 1.0.
// Sets the modelview matrix and the normal matrix of the global program
function drawSphere() {
    setMV() ;
    Sphere.draw() ;
}
// Draws a cylinder along z of height 1 centered at the origin
// and radius 0.5.
// Sets the modelview matrix and the normal matrix of the global program
function drawCylinder() {
    setMV() ;
    Cylinder.draw() ;
}

// Draws a cone along z of height 1 centered at the origin
// and base radius 1.0.
// Sets the modelview matrix and the normal matrix of the global program
function drawCone() {
    setMV() ;
    Cone.draw() ;
}

// Post multiples the modelview matrix with a translation matrix
// and replaces the modelview matrix with the result
function gTranslate(x,y,z) {
    modelMatrix = mult(modelMatrix,translate([x,y,z])) ;
}

// Post multiples the modelview matrix with a rotation matrix
// and replaces the modelview matrix with the result
function gRotate(theta,x,y,z) {
    modelMatrix = mult(modelMatrix,rotate(theta,[x,y,z])) ;
}

// Post multiples the modelview matrix with a scaling matrix
// and replaces the modelview matrix with the result
function gScale(sx,sy,sz) {
    modelMatrix = mult(modelMatrix,scale(sx,sy,sz)) ;
}

// Pops MS and stores the result as the current modelMatrix
function gPop() {
    modelMatrix = MS.pop() ;
}

// pushes the current modelMatrix in the stack MS
function gPush() {
    MS.push(modelMatrix) ;
}

// ------------ Eye viewing settings --------------
function eyeRotating360(time) {
  return vec3(Math.sin(time/2), 0.5,  Math.cos(time/2));;
}

function eyeFrontCenterSlightRotation(time) {
  return vec3(2*Math.sin(time/2), 0.5, 30+2*Math.cos(time/2));
}

function eyeViewFromRightSide(time) {
  return vec3(50+2*Math.sin(time/2), 5, 20+2*Math.cos(time/2));
}

function eyeViewFromLeftSide(time, negatedBol) {
  if (!negatedBol) {
    return vec3(-50+20*Math.sin(time/2), 5, 20+20*Math.cos(time/2));
  }
  return vec3(-50+20*Math.sin(time/2), 5, 20-20*Math.cos(time/2));
}

function render() {

    gl.clear( gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    // gl.uniform4f( gl.getUniformLocation(program, "customColor"), Math.sin(TIME*10), 0.0, 0.0, 1.0 );

    // View TIME (continious) and FRAME RATE (averaged over every 2 seconds)
    viewTimeAndFrameRate() ;


    eye = vec3(0, 0, 10);
    currentTimeInSeconds = Math.floor(TIME);

    // Controlling camera movement
    if (currentTimeInSeconds <= 3) {
      eye = eyeFrontCenterSlightRotation(TIME);
    }
    else if (currentTimeInSeconds <= 10) {
      eye = eyeRotating360(TIME);
    }
    else if (currentTimeInSeconds <= 15) {
      eye = eyeFrontCenterSlightRotation(TIME);
    }
    else if (currentTimeInSeconds <= 19) {
      eye = eyeViewFromRightSide(TIME);
    }
    else if (currentTimeInSeconds <= 25) {
      eye = eyeViewFromLeftSide(TIME, false);
    }
    else if (currentTimeInSeconds <= 28) {
      eye = eyeFrontCenterSlightRotation(TIME);
    }
    else if (currentTimeInSeconds <= 31) {
      eye = eyeViewFromLeftSide(TIME, true);
    }
    else if (currentTimeInSeconds <= 34) {
      eye = eyeFrontCenterSlightRotation(TIME, true);
    }
    else {
      eye = eyeViewFromRightSide(TIME);
    }

    // set the projection matrix
    projectionMatrix = ortho(left, right, bottom, ytop, near, far);

    // set the camera matrix
    viewMatrix = lookAt(eye, at , up);

    // initialize the modeling matrix stack
    MS= [] ;
    modelMatrix = mat4() ;

    // apply the slider rotations
    gRotate(RZ,0,0,1) ;
    gRotate(RY,0,1,0) ;
    gRotate(RX,1,0,0) ;

    // send all the matrices to the shaders
    setAllMatrices() ;

    // get real time
    var curTime ;
    if( animFlag )
    {
        curTime = (new Date()).getTime() /1000 ;
        if( resetTimerFlag ) {
            prevTime = curTime ;
            resetTimerFlag = false ;
        }
        TIME = TIME + curTime - prevTime ;
        prevTime = curTime ;
    }

    /*
    * Plane (textured with grass)
    */
    drawGroundPlane() ;

    /*
    * House Left
    */
    drawLeftHouse() ;

    /*
    * House right
    */
    drawRightHouse() ;

    /*
    * Fence
    */
    drawFence() ;

    /*
    * Drone
    */
    gPush() ;
    {
      // at = vec3(3*Math.sin(TIME), Math.sin(TIME), 0) ;
      gTranslate(3*Math.sin(TIME), Math.sin(TIME), 0) ;
      gTranslate(0.0, -2.0, 0.0) ;
      drawDrone() ;
    }
    gPop() ;

    /*
    * Sheep
    */
    // sheep - stay still at init point
    if (currentTimeInSeconds <= 19) {
      gPush() ;
      {
        gTranslate(5.0, 0.0, 0.0) ;
        drawSheep(false) ;
      }
      gPop() ;
    }

    // move sheep along x axis
    else if (currentTimeInSeconds <= 21) {
      gPush() ;
      {
        sheepLastLoc[0] = 9*Math.sin(TIME/2);
        gTranslate(sheepLastLoc[0], sheepLastLoc[1], sheepLastLoc[2] ) ;
        gTranslate(5.0, 0.0, 0.0) ;
        drawSheep(true) ;
      }
      gPop() ;
    }

    // Keep sheep still for a bit
    else if (currentTimeInSeconds <= 25) {
      gPush() ;
      {
        gTranslate(sheepLastLoc[0], sheepLastLoc[1], sheepLastLoc[2]) ;
        gTranslate(5.0, 0.0, 0.0) ;
        drawSheep(false) ;
      }
      gPop() ;
    }

    // Rotate sheep 90 degrees
    else if (currentTimeInSeconds <= 27) {
      gPush() ;
      {
        gTranslate(sheepLastLoc[0], sheepLastLoc[1], sheepLastLoc[2]) ;
        gTranslate(5.0, 0.0, 0.0) ;
        gRotate(90, 0.0, 1.0, 0.0) ;
        drawSheep(false) ;
      }
      gPop() ;
    }

    // Move sheep along z axis
    else if (currentTimeInSeconds <= 31) {
      gPush() ;
      {
        sheepLastLoc[2] = -6*Math.cos(TIME/2);
        gTranslate(sheepLastLoc[0], sheepLastLoc[1], sheepLastLoc[2]) ;
        gTranslate(5.0, 0.0, 0.0) ;
        gRotate(90, 0.0, 1.0, 0.0) ;
        drawSheep(true) ;
      }
      gPop() ;
    }

    // Keep sheep still for a bit
    else if (currentTimeInSeconds <= 34) {
      gPush() ;
      {
        gTranslate(sheepLastLoc[0], sheepLastLoc[1], sheepLastLoc[2]) ;
        gTranslate(5.0, 0.0, 0.0) ;
        drawSheep(false) ;
      }
      gPop() ;
    }

    // Rotate sheep 90 degrees
    else if (currentTimeInSeconds <= 36) {
      gPush() ;
      {
        gTranslate(sheepLastLoc[0], sheepLastLoc[1], sheepLastLoc[2]) ;
        gTranslate(5.0, 0.0, 0.0) ;
        gRotate(180, 0.0, 1.0, 0.0) ;
        drawSheep(false) ;
      }
      gPop() ;
    }

    // Move sheep along x axis
    else if (currentTimeInSeconds <= 40) {
      gPush() ;
      {
        sheepLastLoc[0] = 5*Math.sin(TIME/2);
        gTranslate(sheepLastLoc[0], sheepLastLoc[1], sheepLastLoc[2]) ;
        gTranslate(-5.0, 0.0, 0.0) ;
        gRotate(180, 0.0, 1.0, 0.0) ;
        drawSheep(true) ;
      }
      gPop() ;
    }

    // Keep sheep still forever
    else {
      gPush() ;
      {
        gTranslate(sheepLastLoc[0], sheepLastLoc[1], sheepLastLoc[2]) ;
        gTranslate(-5.0, 0.0, 0.0) ;
        gRotate(180, 0.0, 1.0, 0.0) ;
        drawSheep(false) ;
      }
      gPop() ;
    }

    /*
    * No entry sign
    */
    activateNoEntryTexture() ;
    gPush() ;
    {
      gTranslate(-9.0, -2.8, 1.3) ;
      gRotate(90, 0.0, 1.0, 0.0) ;
      gScale(1.2, 1.2, 0.1) ;
      drawCube() ;
    }
    gPop() ;

    /*
    * Flashing red light
    */
    gl.uniform1i( gl.getUniformLocation(program, "useTextures"), -1 );
    gl.uniform4f( gl.getUniformLocation(currProg, "customColor"), Math.sin(TIME*10), 0.0, 0.0, 1.1 );
    gPush() ;
    {
      gTranslate(-9.0, -0.38, 1.3) ;
      gRotate(90, 0.0, 1.0, 0.0) ;
      gScale(1.2, 1.2, 0.1) ;
      drawCube() ;
    }
    gPop() ;
    gl.uniform1i( gl.getUniformLocation(program, "useTextures"), useTextures );

    if( animFlag )
        window.requestAnimFrame(render);
}

// A simple camera controller which uses an HTML element as the event
// source for constructing a view matrix. Assign an "onchange"
// function to the controller as follows to receive the updated X and
// Y angles for the camera:
//
//   var controller = new CameraController(canvas);
//   controller.onchange = function(xRot, yRot) { ... };
//
// The view matrix is computed elsewhere.
function CameraController(element) {
    var controller = this;
    this.onchange = null;
    this.xRot = 0;
    this.yRot = 0;
    this.scaleFactor = 3.0;
    this.dragging = false;
    this.curX = 0;
    this.curY = 0;

    // Assign a mouse down handler to the HTML element.
    element.onmousedown = function(ev) {
        controller.dragging = true;
        controller.curX = ev.clientX;
        controller.curY = ev.clientY;
    };

    // Assign a mouse up handler to the HTML element.
    element.onmouseup = function(ev) {
        controller.dragging = false;
    };

    // Assign a mouse move handler to the HTML element.
    element.onmousemove = function(ev) {
        if (controller.dragging) {
            // Determine how far we have moved since the last mouse move
            // event.
            var curX = ev.clientX;
            var curY = ev.clientY;
            var deltaX = (controller.curX - curX) / controller.scaleFactor;
            var deltaY = (controller.curY - curY) / controller.scaleFactor;
            controller.curX = curX;
            controller.curY = curY;
            // Update the X and Y rotation angles based on the mouse motion.
            controller.yRot = (controller.yRot + deltaX) % 360;
            controller.xRot = (controller.xRot + deltaY);
            // Clamp the X rotation to prevent the camera from going upside
            // down.
            if (controller.xRot < -90) {
                controller.xRot = -90;
            } else if (controller.xRot > 90) {
                controller.xRot = 90;
            }
            // Send the onchange event to any listener.
            if (controller.onchange != null) {
                controller.onchange(controller.xRot, controller.yRot);
            }
        }
    };
}


/*
* Helper functions
*/
function drawGroundPlane() {
  activateGrassTexture() ;
  gPush() ;
  {
    setColor(vec4(0.2, 0.0, 0.7 ,0.0)) ;
    gTranslate(0, -5.91, 0) ;
    gScale(10.0, 0.1, 10.0) ;
    drawCube() ;
  }
  gPop() ;
}

function drawScaledCubeAtSpecifiedLocation (sX, sY, sZ, locX, locY, locZ) {
  gTranslate(locX, locY, locZ) ;
  gScale(sX, sY, sZ) ;
  drawCube() ;
}

function drawDroneBody() {
  gPush() ;
  {
    toggleTextures() ;
    gTranslate(0.0, 3.0, 0.0) ;
    gScale(0.8, 0.2, 0.8) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;
}

function drawDroneLeg(locX, locY, locZ) {
  // Drone leg
  gPush() ;
  {
    toggleTextures() ;
    gTranslate(locX, locY, locZ) ;
    gScale(0.1, 0.2, 0.1) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;

  // Drone Foot
  gPush() ;
  {
    toggleTextures() ;
    gTranslate(locX, locY-0.3, locZ) ;
    gScale(0.2, 0.2, 0.2) ;
    gRotate(90, 1.0, 0.0, 0.0) ;
    drawCone() ;
    toggleTextures() ;
  }
  gPop() ;
}

function drawDroneArm() {
  // Drone arm 1 (L1->S1->L2->S2->H1->H2->H3)
  setColor(vec4(0.5,0.7,0.3,1.0)) ;

  // L1
  gPush() ;
  {
    toggleTextures() ;
    gTranslate(1.0, 3.0, 0.5) ;
    gRotate(90, 0.0, 1.0, 0.0) ;
    gScale(0.05, 0.05, 0.2) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;

  // S1
  gPush() ;
  {
    toggleTextures() ;
    gTranslate(1.2, 3.0, 0.5) ;
    gScale(0.12, 0.12, 0.12) ;
    drawSphere() ;
    toggleTextures() ;
  }
  gPop() ;

  // L2
  gPush() ;
  {
    toggleTextures() ;
    gTranslate(1.2, 3.2, 0.5) ;
    gRotate(90, 1.0, 0.0, 0.0) ;
    gScale(0.05, 0.05, 0.2) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;

  // S2
  gPush() ;
  {
    toggleTextures() ;
    gTranslate(1.2, 3.42, 0.5) ;
    gScale(0.1, 0.1, 0.1) ;
    drawSphere() ;
    toggleTextures() ;
  }
  gPop() ;

  // H1
  gPush() ;
  {
    toggleTextures() ;
    gTranslate(1.2, 3.4, 0.5) ;
    gRotate(TIME*250, 0.0, 1.0, 0.0) ;
    gTranslate(0.28, 0.0, 0.18) ;
    gRotate(60, 0.0, 1.0, 0.0) ;
    gScale(0.05, 0.05, 0.2) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;

  // H2
  gPush() ;
  {
    toggleTextures() ;
    gTranslate(1.2, 3.4, 0.5) ;
    gRotate(TIME*250, 0.0, 1.0, 0.0) ;
    gTranslate(-0.28, 0.0, 0.18) ;
    gRotate(120, 0.0, 1.0, 0.0) ;
    gScale(0.05, 0.05, 0.2) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;

  // H3
  gPush() ;
  {
    toggleTextures() ;
    gTranslate(1.2, 3.4, 0.5) ;
    gRotate(TIME*250, 0.0, 1.0, 0.0) ;
    gTranslate(0.0, 0.0, -0.33) ;
    gRotate(180, 0.0, 1.0, 0.0) ;
    gScale(0.05, 0.05, 0.2) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;
}

function drawDrone() {
  // Drone body
  drawDroneBody() ;

  // Drone leg 1
  drawDroneLeg(0.5, 2.6, 0.5) ;

  // Dorone leg 2
  drawDroneLeg(-0.5, 2.6, 0.5) ;

  // Drone leg 3
  drawDroneLeg(0.5, 2.6, -0.5) ;

  // Drone leg 4
  drawDroneLeg(-0.5, 2.6, -0.5) ;

  // Drone arm 1
  gPush() ;
  {
    drawDroneArm() ;
  }
  gPop() ;

  // Drone arm 2
  gPush() ;
  {
    gTranslate(0.0, 0.0, -1.0) ;
    drawDroneArm() ;
  }
  gPop() ;

  // Drone arm 3
  gPush() ;
  {
    gTranslate(-0.7, 3.0, -1.0) ; // move to wherevr desired
    gRotate(180, 0.0, 1.0, 0.0) ; // rotate about origin
    gTranslate(-0.68, -3.0, -1.0) ; // move it to origin
    drawDroneArm() ;
  }
  gPop() ;

  // Drone arm 4
  gPush() ;
  {
    gTranslate(-0.7, 3.0, -0.05) ; // move to wherevr desired
    gRotate(180, 0.0, 1.0, 0.0) ; // rotate about origin
    gTranslate(-0.68, -3.0, -1.0) ; // move it to origin
    drawDroneArm() ;
  }
  gPop() ;
}

function drawSheepLeg(animateBol) {
  // Sheep leg
  gPush() ;
  {
    toggleTextures() ;
    setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
    gTranslate(0.8, -5.1, 0.5) ;
    gTranslate(0.0, 0.5, 0.0) ;
    if (animateBol) {
      gRotate(10*Math.sin(10*TIME), 0.0, 0.0, 1.0)
    }
    gTranslate(0.0, -0.5, 0.0) ;
    gScale(0.1, 0.5, 0.1) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;

  // Sheep foot
  gPush() ;
  {
    toggleTextures() ;
    setColor(vec4(1.0, 0.6, 0.0 ,1.0)) ;
    if (animateBol) {
      gTranslate(0.1*Math.sin(10*TIME), 0.0, 0.0)
    }
    gTranslate(0.8, -5.7, 0.5) ;
    gScale(0.1, 0.1, 0.1) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;
}

function drawSheepEye() {
  // Eye white
  gPush() ;
  {
    toggleTextures() ;
    setColor(vec4(1.2, 1.6, 1.0 ,1.0)) ;
    gTranslate(-2.7, -3.2, -0.15) ;
    gRotate(50, 0.0, 0.0, 1.0) ;
    gScale(0.1, 0.1, 0.1) ;
    drawSphere() ;
    toggleTextures() ;
  }
  gPop() ;

  // Eye black
  gPush() ;
  {
    toggleTextures() ;
    setColor(vec4(0.0, 0.0, 0.0 ,1.0)) ;
    gTranslate(-2.8, -3.2, -0.15) ;
    gRotate(50, 0.0, 0.0, 1.0) ;
    gScale(0.06, 0.06, 0.06) ;
    drawSphere() ;
    toggleTextures() ;
  }
  gPop() ;
}

function drawSheepNeckAndFace(animateBol) {
  gPush() ;
  {
    if (animateBol) {
      gRotate(20*Math.sin(2*TIME), 0.0, 1.0, 0.0) ; // left-right movement
    }

    // sheep neck
    gPush() ;
    {
      toggleTextures() ;
      setColor(vec4(1.0, 0.6, 0.0 ,1.0)) ;
      gTranslate(-1.5, -4.3, 0.0) ;
      gRotate(-70, 0.0, 0.0, 1.0) ;
      gScale(0.3, 0.6, 0.3) ;
      drawCube() ;
      toggleTextures() ;
    }
    gPop() ;

    // sheep face
    gPush() ;
    {
      toggleTextures() ;
      setColor(vec4(1.0, 0.6, 1.0 ,1.0)) ;
      gTranslate(-2.5, -4.6, 0.0) ;
      gRotate(50, 0.0, 0.0, 1.0) ;
      gScale(0.5, 0.5, 0.5) ;
      drawSphere() ;
      toggleTextures() ;
    }
    gPop() ;

    // eyes
    gPush() ;
    {
      gTranslate(-0.2, -1.2, 0.0) ;

      // sheep eye 1
      drawSheepEye() ;

      // sheep eye 2
      gPush() ;
      {
        gTranslate(0.0, 0.0, 0.4) ;
        drawSheepEye() ;
      }
      gPop() ;
    }
    gPop() ;

    // mouth
    gPush() ;
    {
      gTranslate(-0.2, -1.2, 0.0) ;
      drawSheepMouth() ;
    }
    gPop() ;
  }
  gPop() ;
}

function drawSheepMouth() {
  // sheep mouth
  gPush() ;
  {
    toggleTextures() ;
    setColor(vec4(0.5, 0.5, 0.5 ,1.0)) ;
    gTranslate(-2.9, -3.6, 0.0) ;
    gRotate(20, 0.0, 0.0, 1.0) ;
    gScale(0.2, 0.2, 0.2) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;

  // sheep nose
  gPush() ;
  {
    toggleTextures() ;
    setColor(vec4(0.0, 0.0, 0.0 ,1.0)) ;
    gTranslate(-3.23, -3.62, 0.0) ;
    gRotate(20, 0.0, 0.0, 1.0) ;
    gScale(0.1, 0.1, 0.2) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;

  // sheep under nose
  gPush() ;
  {
    toggleTextures() ;
    setColor(vec4(0.5, 0.5, 0.5 ,1.0)) ;
    gTranslate(-3.15, -3.80, 0.0) ;
    gRotate(20, 0.0, 0.0, 1.0) ;
    gScale(0.1, 0.1, 0.2) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;
}

function drawSheep(animateBol) {
  gPush() ;
  {
    // sheep body
    gPush() ;
    {
      toggleTextures() ;
      gTranslate(0.0, -4.1, 0.0) ;
      gScale(1.2, 0.5, 0.8) ;
      drawCube() ;
      toggleTextures() ;
    }
    gPop() ;

    // sheep leg 1
    gPush() ;
    {
      drawSheepLeg(animateBol) ;
    }
    gPop() ;

    // sheep leg 2
    gPush() ;
    {
      gTranslate(-1.6, 0.0, 0.0) ;
      drawSheepLeg(animateBol) ;
    }
    gPop() ;

    // sheep leg 3
    gPush() ;
    {
      gTranslate(0.0, 0.0, -1.0) ;
      drawSheepLeg(animateBol) ;
    }
    gPop() ;

    // sheep leg 4
    gPush() ;
    {
      gTranslate(-1.6, 0.0, -1.0) ;
      drawSheepLeg(animateBol) ;
    }
    gPop() ;

    // sheep tail
    gPush() ;
    {
      toggleTextures() ;
      setColor(vec4(0.0, 0.6, 0.0 ,1.0)) ;
      gTranslate(1.5, -4.4, 0.0) ;
      gRotate(10*Math.sin(10*TIME), 1.0, 0.0, 0.0)
      gRotate(45, 0.0, 0.0, 1.0) ;
      gScale(0.1, 0.8, 0.1) ;
      drawCube() ;
      toggleTextures() ;
    }
    gPop() ;

    drawSheepNeckAndFace(true) ;
  }
  gPop() ;

}

function drawFencePart() {
  // Fence 0
  gPush() ;
  {
    toggleTextures() ;
    gScale(0.15, 1, 0.15) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;

  // Fence 90
  gPush() ;
  {
    toggleTextures() ;
    gTranslate(0.0, 0.4, 1.19) ;
    gRotate(90, 1.0, 0.0, 0.0) ;
    gScale(0.15, 1, 0.15) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;

  // Fence 90
  gPush() ;
  {
    toggleTextures() ;
    gTranslate(0.0, -0.4, 1.19) ;
    gRotate(90, 1.0, 0.0, 0.0) ;
    gScale(0.15, 1, 0.15) ;
    drawCube() ;
    toggleTextures() ;
  }
  gPop() ;
}

function drawFence() {
  for (var i=0; i<8; i++) {
    gPush() ;
    {
      toggleTextures() ;
      gTranslate(9.5, -5.0, -9.0 + i*2.3) ;
      drawFencePart() ;
      toggleTextures() ;
    }
    gPop() ;
  }

  for (var i=0; i<8; i++) {
    gPush() ;
    {
      toggleTextures() ;
      gTranslate(9.5 - i*2.3, -5.0, -9.0 + 8*2.3) ;
      gRotate(90, 0.0, -1.0, 0.0) ;
      drawFencePart() ;
      toggleTextures() ;
    }
    gPop() ;
  }

  for (var i=0; i<8; i++) {
    gPush() ;
    {
      toggleTextures() ;
      gTranslate(9.5 - 8*2.3, -5.0, -9.0 + 8*2.3 - i*2.3) ;
      gRotate(180, 0.0, -1.0, 0.0) ;
      drawFencePart() ;
      toggleTextures() ;
    }
    gPop() ;
  }

  for (var i=0; i<8; i++) {
    gPush() ;
    {
      toggleTextures() ;
      gTranslate(9.5 - 8*2.3 + i*2.3, -5.0, -9.0 + 8*2.3 - 8*2.3) ;
      gRotate(270, 0.0, -1.0, 0.0) ;
      drawFencePart() ;
      toggleTextures() ;
    }
    gPop() ;
  }
}

function viewTimeAndFrameRate() {
  // Display time for syncronization and debugging purposes
  document.getElementById("time_value").innerHTML = TIME.toString();

  // Update frame count and frame rate
  frameCount += 1;

  // Update frame rate every 2 secodns
  if ((Math.floor(TIME) % 2 == 0) && (Math.floor(TIME) > lastTimeFrameRateSeconds)) {
    document.getElementById("frame_rate_value").innerHTML = (frameCount/2).toString();
    lastTimeFrameRateSeconds = Math.floor(TIME);
    frameCount = 0;
  }
}

function activateDoorTexture() {
  gl.activeTexture(gl.TEXTURE0);
  gl.bindTexture(gl.TEXTURE_2D, textureArray[0].textureWebGL);
  gl.uniform1i(gl.getUniformLocation(program, "texture1"), 0);
}

function activateGrassTexture() {
  gl.activeTexture(gl.TEXTURE0);
  gl.bindTexture(gl.TEXTURE_2D, textureArray[1].textureWebGL);
  gl.uniform1i(gl.getUniformLocation(program, "texture2"), 1);
}

function activateWindowTexture() {
  gl.activeTexture(gl.TEXTURE0);
  gl.bindTexture(gl.TEXTURE_2D, textureArray[2].textureWebGL);
  gl.uniform1i(gl.getUniformLocation(program, "texture3"), 2);
}

function activateStoneTexture() {
  gl.activeTexture(gl.TEXTURE0);
  gl.bindTexture(gl.TEXTURE_2D, textureArray[3].textureWebGL);
  gl.uniform1i(gl.getUniformLocation(program, "texture4"), 3);
}

function activateNoEntryTexture() {
  gl.activeTexture(gl.TEXTURE0);
  gl.bindTexture(gl.TEXTURE_2D, textureArray[4].textureWebGL);
  gl.uniform1i(gl.getUniformLocation(program, "texture5"), 4);
}

function drawRightHouse() {
  activateStoneTexture() ;
  gPush() ;
  {
      drawScaledCubeAtSpecifiedLocation (3.0, 4.0, 2.0, 2.0, -2.0, -6.0) ;
  }
  gPop() ;

  // House Door
  activateDoorTexture() ;
  gPush() ;
  {
      // toggleTextures () ;
      drawScaledCubeAtSpecifiedLocation (1.0, 2.0, 0.1, 2.0, -4.0, -4.0) ;
      // toggleTextures () ;
  }
  gPop() ;

  activateWindowTexture() ;
  // Window left
  gPush() ;
  {
      // toggleTextures () ;
      drawScaledCubeAtSpecifiedLocation (1.0, 1.2, 0.1, 0.5, 0.5, -4.0) ;
      // toggleTextures () ;
  }
  gPop() ;

  // Window right
  // Window
  gPush() ;
  {
      // toggleTextures () ;
      drawScaledCubeAtSpecifiedLocation (1.0, 1.2, 0.1, 3.5, 0.5, -4.0) ;
      // toggleTextures () ;
  }
  gPop() ;
}

function drawLeftHouse() {
  activateStoneTexture() ;
  gPush() ;
  {
      drawScaledCubeAtSpecifiedLocation (3.0, 4.0, 2.0, -5.0, -2.0, -6.0) ;
  }
  gPop() ;

  activateDoorTexture() ;
  // House Door Left
  gPush() ;
  {
      // toggleTextures () ;
      drawScaledCubeAtSpecifiedLocation (1.0, 2.0, 0.1, -6.5, -4.0, -4.0) ;
      // toggleTextures () ;
  }
  gPop() ;

  // House Door Right
  gPush() ;
  {
      // toggleTextures () ;
      drawScaledCubeAtSpecifiedLocation (1.0, 2.0, 0.1, -3.5, -4.0, -4.0) ;
      // toggleTextures () ;
  }
  gPop() ;

  activateWindowTexture() ;
  // House window right top
  gPush() ;
  {
      // toggleTextures () ;
      drawScaledCubeAtSpecifiedLocation (0.7, 0.7, 0.1, -3.5, 1.0, -4.0) ;
      // toggleTextures () ;
  }
  gPop() ;

  // House window right bottom
  gPush() ;
  {
      // toggleTextures () ;
      drawScaledCubeAtSpecifiedLocation (0.7, 0.7, 0.1, -3.5, -0.6, -4.0) ;
      // toggleTextures () ;
  }
  gPop() ;

  // House window left top
  gPush() ;
  {
      // toggleTextures () ;
      drawScaledCubeAtSpecifiedLocation (0.7, 0.7, 0.1, -6.5, 1.0, -4.0) ;
      // toggleTextures () ;
  }
  gPop() ;

  // House window left bottom
  gPush() ;
  {
      // toggleTextures () ;
      drawScaledCubeAtSpecifiedLocation (0.7, 0.7, 0.1, -6.5, -0.6, -4.0) ;
      // toggleTextures () ;
  }
  gPop() ;
}
