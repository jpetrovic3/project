//add includes to header file + guard files


int main()
{
  //set initial parameters, open camera, enable object tracking
  //create camara objects
    Camera zed;

    //initiate camara parameters
    InitParameters init_parameters;
    init_parameters.camera_resolution = RESOLUTION::HD720;
    init_parameters.depth_mode = DEPTH_MODE::PERFORMANCE;
    init_parameters.coordinate_units = UNIT::METER;
    init_parameters.sdk_verbose = true;

    // Open the camera
    auto returned_state = zed.open(init_parameters);

    // if error  close camara
    if (returned_state != ERROR_CODE::SUCCESS) {
        cout << "Error " << returned_state << ", exit program.\n";
        return EXIT_FAILURE;
    }

    //creating sl and cv Mat
    Resolution image_size = zed.getCameraInformation().camera_resolution;
    int new_width = image_size.width;
    int new_height = image_size.height;

    Mat image_zed(new_width, new_height, MAT_TYPE::U8_C4);
    cv::Mat image_ocv = slMat2cvMat(image_zed);

    //object detection parameters
    ObjectDetectionParameters detection_parameters;

    //enable positional tracking
    if(detection_parameters.enable_tracking)
        zed.enablePositionalTracking();  


    cout << "loading modules  ..." << endl;

    auto err_code = zed.enableObjectDetection(detection_parameters);



    if(err_code != ERROR_CODE::SUCCESS)
    {
        zed.close();
        return 1;

    }

    //runtime parameters 
    ObjectDetectionRuntimeParameters run_parameters;
    run_parameters.detection_confidence_threshold = 40.f;

    //creating object
    Objects object;

    //image 
    Mat image;

    //depth map 
    Mat depth_map;

    cout << "starting object detection" << endl;


}
