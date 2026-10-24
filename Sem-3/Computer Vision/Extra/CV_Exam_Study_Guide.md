# Computer Vision — Exam Study Guide (Unit 1–4)
*Prioritized for a 25-mark theory exam. Unit 1 & 2 = assignment-mapped (high certainty). Unit 3 & 4 = concept-level (no assignment given).*

---

## UNIT 1 — Computer Vision & Applications

### 1. What is Computer Vision? Scope, relation to Image Processing & AI
- CV = enabling machines to "understand" content of images/video (extract meaning, not just pixels).
- Image Processing: pixel-in → pixel-out (enhance/transform image). CV: pixel-in → description/decision-out.
- Relation to AI: CV uses ML/DL (a sub-field of AI) as tools to interpret visual data; AI provides reasoning, CV provides perception.

### 2. Applications overview
- **Medical imaging**: tumor detection, MRI/CT segmentation, diagnosis assistance.
- **Robotics**: object grasping, navigation, obstacle avoidance.
- **Surveillance**: face/person detection, anomaly/activity recognition.
- **Autonomous vehicles**: lane detection, pedestrian/object detection, depth estimation.

### 3. Image Formation Model — Monocular Imaging System
- Single camera views a 3D scene → 2D image via projection.
- Depends on: scene geometry, illumination, surface reflectance, camera optics (lens, aperture, focal length).
- Loses depth info (3D→2D is many-to-one mapping) — this is why depth-recovery techniques (stereo, shading, defocus) matter.

### 4. Radiosity
- Physics-based model of light transfer between surfaces — models how light bounces/interreflects.
- Radiosity = total energy leaving a surface per unit area (emitted + reflected).
- Used to model realistic image formation, especially indirect illumination.

### 5. Radiance & Irradiance
- **Irradiance**: power of light incident on a surface per unit area (W/m²) — light *arriving*.
- **Radiance**: power per unit area per unit solid angle, in a given direction — light *leaving/traveling* in a direction.
- Relationship: irradiance is radiance integrated over incoming directions (weighted by cosine of angle).

### 6. BRDF
- Bidirectional Reflectance Distribution Function: describes how much light reflected in an outgoing direction given incoming direction.
- BRDF(θi, φi, θo, φo) = ratio of reflected radiance to incident irradiance.
- Models surface reflectance types: diffuse (Lambertian), specular, glossy.
- Used to simulate/predict surface appearance under different lighting.

### 7. Color formation & representation
- Color = wavelength-dependent reflectance × illumination spectrum, sensed by RGB-sensitive receptors/sensors.
- Color spaces: RGB, HSV, YCbCr, Lab.
- Important in CV for segmentation, object recognition, robustness to lighting change (using illumination-invariant color spaces).

### 8. Orthographic vs Perspective Projection
| Orthographic | Perspective |
|---|---|
| Parallel projection rays | Rays converge at a center of projection |
| No depth-based size change | Objects farther away appear smaller |
| Used for far-away/telephoto approx | Models real camera/eye view |
| Simpler math (no division by depth) | Requires division by Z (depth) |
*(Draw two simple diagrams: parallel lines to image plane vs converging lines to a point.)*

### 9. Camera Model — Intrinsic & Extrinsic Parameters
- **Extrinsic**: rotation (R) + translation (T) — relates world coordinates to camera coordinates (camera pose).
- **Intrinsic**: focal length, principal point, skew, pixel scaling — relates camera coords to pixel/image coords.
- Combined: Pixel = K [R|T] * World_point (K = intrinsic matrix).

### 10. Camera Calibration
- Purpose: estimate intrinsic + extrinsic parameters for accurate 3D↔2D mapping.
- Procedure: capture images of a known calibration pattern (e.g., checkerboard) from multiple angles → detect corner points → solve for parameters minimizing reprojection error (e.g., Zhang's method).

### 11. Binocular Imaging Systems
- Two cameras (like human eyes) capture same scene from different viewpoints.
- Disparity (difference in position of corresponding points) → used to compute depth (stereo triangulation).
- Core to depth perception in stereo vision.

### 12. Multiple View Geometry
- Studies geometric relationships between 2+ images of same scene (epipolar geometry, fundamental/essential matrix).
- Significance: enables 3D reconstruction, camera pose estimation, correspondence matching across views.

### 13. Structure Determination
- Recovering 3D structure (shape/geometry) of scene from 2D image(s) — e.g., via triangulation from multiple views or motion (Structure from Motion).

### 14. Shape from Shading
- Recovers 3D shape from variation of brightness/shading in a single image.
- Assumptions: known light source direction, Lambertian (diffuse) surface, known reflectance.
- Steps: model image irradiance equation → relate surface gradient to brightness → solve (often via PDE) for surface normals → integrate to get shape.

### 15. Photometric Stereo & Depth from Defocus
- **Photometric Stereo**: multiple images of *same viewpoint*, *different known lighting directions* → solve for surface normals (more robust than single-image shading).
- **Depth from Defocus**: use blur amount (varies with distance from focal plane) across images at different focus settings to estimate depth.
- **3D model construction**: combine normals/depth maps from these techniques + integrate over surface → generate 3D mesh/model.

---

## UNIT 2 — Image Representation & Pre-processing

### 1. Discrete vs Continuous Image Representation; Sampling & Quantization
- Continuous image: f(x,y) — real-valued function over continuous spatial coordinates and intensity.
- Discrete image: sampled at grid points, intensity quantized to finite levels.
- **Sampling**: converts continuous spatial domain → discrete grid (pixels). Sampling rate must satisfy Nyquist to avoid aliasing.
- **Quantization**: converts continuous intensity → finite set of discrete levels (e.g., 0–255 for 8-bit).

### 2. Image Enhancement — Spatial vs Frequency Domain
- **Enhancement** = improving visual quality/interpretability (contrast, sharpness) — no attempt to model degradation.
- **Spatial domain**: operate directly on pixel values, e.g., histogram equalization, contrast stretching, spatial filtering (smoothing/sharpening kernels).
- **Frequency domain**: transform image (via Fourier Transform), modify frequency components (e.g., low-pass to smooth, high-pass to sharpen), inverse transform back.

### 3. Image Restoration
- Process of recovering original image from a **degraded** version using knowledge of degradation process (blur, noise).
- Differs from enhancement: restoration is *objective* (model-based, reverses known degradation); enhancement is *subjective* (visual improvement, no degradation model).
- **Degradation model**: g(x,y) = f(x,y) * h(x,y) + n(x,y) — degraded image = original convolved with degradation function h, plus noise n. Restoration estimates f from g using known/estimated h and noise statistics (e.g., inverse filtering, Wiener filtering).

### 4. Histogram Equalization
- Redistributes intensity values to produce a more uniform histogram → improves global contrast.
- Steps:
  1. Compute histogram h(rk) = count of pixels with intensity rk.
  2. Compute normalized PDF: p(rk) = nk/N (N = total pixels).
  3. Compute CDF: s_k = Σ p(rj) for j=0 to k.
  4. Map new intensity: s_k = (L-1) × CDF(rk), round to nearest integer (L = number of gray levels).
  5. Replace each pixel's original intensity with mapped s_k.

### 5. Histogram Matching (Specification)
- Transforms image histogram to match a **specified/target** histogram (not necessarily uniform).
- Difference from equalization: equalization targets uniform distribution; matching targets any desired distribution.
- Procedure: equalize input image → equalize target histogram → use inverse mapping of target's equalization to map input's equalized values to matched output.
- Application: matching exposure/contrast across images taken under different conditions (e.g., satellite images from different times).

### 6. Contour-based vs Region-based Shape Representation
| Contour-based | Region-based |
|---|---|
| Represents boundary/outline only | Represents entire region/area |
| E.g., chain codes, Fourier descriptors | E.g., moments, region descriptors |
| Efficient for boundary-focused shapes | Better for shapes with holes/complex interior |
| Sensitive to noise on boundary | More robust to boundary noise |

### 7. Chain Codes & Boundary Descriptors
- **Chain code**: represents contour as sequence of direction codes (e.g., 0–7 for 8-connectivity) between consecutive boundary points.
- **Boundary descriptors**: derived features like perimeter, curvature, bounding box, shape signature (distance from centroid vs angle).

### 8. Region-based Representation — Moments & Descriptors
- **Moments**: statistical measures (area = 0th moment, centroid from 1st moment, orientation/spread from 2nd moment) describing region shape.
- **Region descriptors**: area, perimeter, compactness, eccentricity, Euler number.
- Used for shape matching/classification.

### 9. Deformable Curves & Surfaces
- Curves/surfaces that can change shape (deform) under internal constraints + external image forces to fit object boundaries.
- Significance: handle irregular, non-rigid, or noisy object boundaries better than rigid templates — foundation for snakes/active contours.

### 10. Snakes (Active Contour Models)
- Energy-minimizing curve that deforms to fit/wrap around an object boundary.
- Framework: define energy functional E = E_internal + E_external; iteratively move contour points to minimize total energy → converges to object boundary.

### 11. Internal & External Energy Terms
- **Internal energy**: controls smoothness — elasticity (stretching) + rigidity (bending) terms — keeps contour smooth/continuous.
- **External energy**: derived from image (e.g., gradient magnitude) — pulls contour toward edges/features.
- Balance between the two determines final contour shape.

### 12. Limitations of Traditional Snakes & Improvements
- Limitations: sensitive to initialization, poor convergence into concave boundaries, cannot handle topology changes (splitting/merging).
- Improvements: Gradient Vector Flow (GVF) snakes (better capture range), balloon forces, level-set based active contours (handle topology changes).

### 13. Level Set Method
- Represents contour implicitly as the zero level set of a higher-dimensional function φ(x,y,t).
- Contour evolves by evolving φ over time via PDE.
- Naturally handles topology changes (splitting/merging) since it's an implicit representation — no need to explicitly track points.

### 14. Snakes vs Level Sets
- Snakes: explicit, parametric, faster but topology-fixed, sensitive to initialization.
- Level sets: implicit, handles topology change naturally, more computationally expensive, more robust to complex shapes.

### 15. Fourier Descriptors
- Represent shape boundary as a sequence of complex numbers (x+iy) traversed around contour → apply Discrete Fourier Transform.
- Low-frequency coefficients capture overall shape; high-frequency capture fine detail.
- Compact, rotation/scale/translation invariant (with normalization) shape representation.

### 16. Wavelet Descriptors
- Use wavelet transform (instead of Fourier) on boundary signal — provides both frequency AND spatial/location information (multiresolution).
- Difference from Fourier: Fourier gives global frequency info only; wavelets capture local shape detail at multiple scales — better for shapes with localized features.

### 17. Medial Representations / Medial Axis Transform
- Medial axis = set of points equidistant from at least two boundary points (skeleton of the shape).
- Captures shape's topology and structure compactly; used in shape description, matching, and skeletonization.

### 18. Multiresolution Analysis
- Analyzing an image at multiple scales/resolutions simultaneously.
- Helps detect features at different sizes, reduces computation (coarse-to-fine processing), useful for compression and analysis of both global and fine details.

### 19. Gaussian & Laplacian Pyramids
- **Gaussian pyramid**: successively blur + downsample image → sequence of images at decreasing resolution.
- **Laplacian pyramid**: difference between Gaussian pyramid level and upsampled next level → captures band-pass detail (edges) at each scale.
- Used in multiresolution analysis, blending, compression, feature detection at scale.

### 20. Fourier vs Wavelet vs Medial Axis — Comparison
| Method | Captures | Strength | Limitation |
|---|---|---|---|
| Fourier descriptors | Global frequency of boundary | Compact, invariant to rotation/scale | Poor at localized detail |
| Wavelet descriptors | Multi-scale local + global | Good for localized features | More complex to compute |
| Medial axis | Skeleton/topology | Intuitive structural representation | Sensitive to boundary noise |

---

## UNIT 3 — Feature Extraction (concept-level; no assignment given)

- **Canny edge detector**: Gaussian smoothing → gradient (magnitude+direction) → non-max suppression → double threshold + hysteresis linking.
- **LOG (Laplacian of Gaussian)** / **DOG (Difference of Gaussian)**: blob/edge detectors; DOG approximates LOG efficiently, used in SIFT for scale-space extrema detection.
- **Hough Transform**: detects lines (or shapes) by mapping edge points to a parameter space (e.g., ρ-θ) and finding accumulator peaks = detected lines.
- **Harris Corner Detector**: uses local intensity gradient structure (second-moment matrix) — corner where both eigenvalues of the matrix are large.
- **Hessian Affine**: corner/blob detector using Hessian matrix, affine-invariant region detection.
- **Orientation Histogram / HOG**: histogram of gradient directions in local cells — used for shape/object description (e.g., pedestrian detection).
- **SIFT**: scale-invariant keypoints via DOG scale-space, assigns orientation, builds descriptor from local gradient histograms — robust to scale/rotation.
- **SURF**: faster approximation of SIFT using integral images and box filters.
- **GLOH**: SIFT variant using log-polar location grid, higher dimensional but more distinctive.
- **Scale-Space / Image Pyramids**: represent image at multiple scales (via Gaussian smoothing + downsampling) to detect features robust to scale change.
- **Gabor Filters**: band-pass filters sensitive to specific frequency + orientation — used for texture analysis.
- **DWT (Discrete Wavelet Transform)**: multiresolution decomposition — used for feature extraction/compression capturing both frequency and spatial info.

## UNIT 4 — Image Segmentation (concept-level; no assignment given)

- **Region Growing**: start from seed pixel(s), grow region by adding neighboring pixels with similar properties (intensity/texture) until criteria fail.
- **Edge-based Segmentation**: detect edges (via gradient operators) then link them to form region boundaries.
- **Graph-Cut**: models image as a graph (pixels = nodes), finds minimum cut separating foreground/background based on edge weights (similarity).
- **Mean-Shift**: mode-seeking algorithm — iteratively shifts points toward density peaks in feature space, clusters = segments.
- **MRFs (Markov Random Fields)**: probabilistic model — pixel label depends on neighboring pixel labels, used for smooth/context-aware segmentation.
- **Texture Segmentation**: segments regions based on texture features (not just intensity), e.g., using Gabor filter responses or co-occurrence statistics.
- **Object Detection & Recognition**: broader task — localize (bounding box) + classify objects, often builds on segmentation + feature extraction (HOG, SIFT) + classifiers.

---

## Suggested Study Order (given your timeline)
1. Unit 1 (Q3–10 first — image formation, radiance/irradiance/BRDF, projections, camera model) — highest yield.
2. Unit 2 (Q4 histogram equalization math — practice writing the steps; Q10–14 snakes/level sets; Q15–16 Fourier/wavelet).
3. Unit 3 — read once, focus on Canny, Harris, SIFT, Hough.
4. Unit 4 — read once, focus on region growing, graph-cut, mean-shift.
5. Final pass: re-skim Unit 1 & 2 headers only, to refresh recall right before sleep/exam.
