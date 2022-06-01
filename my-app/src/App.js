
import React, { useRef, useState } from "react"
import Webcam from "react-webcam"


function App() {

  const webcamRef = useRef(null);

  const [image, setImage] = useState('');

  const handleClick = () => {
    const imageSrc = webcamRef.current.getScreenshot();
    
    setImage(imageSrc);
    console.log(imageSrc);
  }

  const videoConstraints = {
    width: 1280,
    height: 720,
    facingMode: "user"
  };

  return (
    <div className='camera'>
      <div className='container'>
        <Webcam audio={false}
        ref={webcamRef} 
        screenshotFormat="image/jpeg"
        videoConstraints={videoConstraints}
        ></Webcam>
        <button onClick={handleClick}>CAPTURE !</button>
      </div>
      <img src={image} />
    </div>
  )
};

export default App;
