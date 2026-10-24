# Computer Vision — Cheat Sheet (All 4 Units)
*Quick-glance keywords & one-liners. For full answers see the Study Guide.*

---

## UNIT 1 — CV & Applications
- **CV vs IP**: IP = pixel→pixel; CV = pixel→meaning/decision. AI = reasoning; CV = perception (sub-tool of AI).
- **Apps**: Medical (tumor/segmentation), Robotics (grasp/navigate), Surveillance (detect/track), Autonomous vehicles (lane/pedestrian/depth).
- **Monocular imaging**: 3D→2D projection; loses depth (many-to-one mapping).
- **Radiosity**: total energy leaving surface (emitted+reflected); models interreflection.
- **Irradiance**: light *incident* on surface (W/m²). **Radiance**: light *leaving* in a direction (per solid angle). Irradiance = ∫ Radiance·cosθ.
- **BRDF**: f(θi,φi,θo,φo) = reflected radiance / incident irradiance. Types: diffuse, specular, glossy.
- **Color**: wavelength reflectance × illumination → sensed RGB. Spaces: RGB, HSV, YCbCr, Lab.
- **Orthographic**: parallel rays, no depth scaling. **Perspective**: rays converge, far = smaller, needs ÷Z.
- **Camera model**: Pixel = K[R|T]·World. **Intrinsic** K = focal length, principal pt, skew. **Extrinsic** = R (rotation) + T (translation).
- **Calibration**: known pattern (checkerboard) → multiple views → solve params minimizing reprojection error (Zhang's method).
- **Binocular**: 2 cameras → disparity → depth via triangulation.
- **Multiple view geometry**: epipolar geometry, fundamental/essential matrix → 3D reconstruction, pose estimation.
- **Structure determination**: recover 3D structure from 2D views (e.g. Structure from Motion).
- **Shape from shading**: single image, brightness→surface normal; assumes known light dir + Lambertian surface.
- **Photometric stereo**: same view, multiple known lighting → solve normals (more robust than shading alone).
- **Depth from defocus**: blur amount at different focus settings → estimate depth.

---

## UNIT 2 — Image Representation & Pre-processing
- **Sampling**: continuous→discrete spatial grid (Nyquist to avoid aliasing). **Quantization**: continuous→discrete intensity levels.
- **Enhancement**: subjective, visual quality, no degradation model. **Spatial domain**: direct pixel ops (histogram eq, filtering). **Frequency domain**: FT → modify freq → inverse FT.
- **Restoration**: objective, reverses *known* degradation. Model: g = f*h + n (degraded = original⊛blur + noise). Methods: inverse filter, Wiener filter.
- **Histogram Equalization steps**: 1) histogram h(rk) 2) PDF p(rk)=nk/N 3) CDF s_k=Σp(rj) 4) s_k=(L-1)·CDF, round 5) remap pixels.
- **Histogram Matching**: equalize input, equalize target, use inverse of target's mapping → match distributions (not just uniform). Use: matching exposure across images.
- **Contour-based** (boundary only: chain codes, Fourier desc.) **vs Region-based** (whole area: moments, descriptors) — region more robust to boundary noise.
- **Chain code**: direction sequence (0–7) along boundary. **Boundary descriptors**: perimeter, curvature, shape signature.
- **Moments**: 0th=area, 1st=centroid, 2nd=orientation/spread.
- **Deformable curves/surfaces**: shape-changing models fitted via internal constraints + external image forces → base for snakes.
- **Snakes**: E = E_internal + E_external, minimize iteratively to fit boundary.
- **Internal energy**: elasticity+rigidity (smoothness). **External energy**: image gradient (pulls to edges).
- **Snake limitations**: init-sensitive, poor concave convergence, no topology change. **Fix**: GVF snakes, balloon force, level sets.
- **Level sets**: contour = zero level of φ(x,y,t); handles split/merge naturally (implicit rep).
- **Snakes vs Level sets**: explicit/fast/topology-fixed vs implicit/robust/expensive.
- **Fourier descriptors**: boundary as complex sequence → DFT; low-freq=overall shape, high-freq=detail. Invariant (normalized).
- **Wavelet descriptors**: multiresolution, local+global (vs Fourier's global-only).
- **Medial axis**: points equidistant from ≥2 boundary points = skeleton; captures topology.
- **Multiresolution analysis**: analyze at multiple scales → coarse-to-fine, compression, multi-size feature detection.
- **Gaussian pyramid**: blur+downsample repeatedly. **Laplacian pyramid**: Gaussian level − upsampled next level = band-pass detail.
- **Comparison**: Fourier=global/compact; Wavelet=multi-scale/local; Medial axis=structural/topology, noise-sensitive.

---

## UNIT 3 — Feature Extraction
- **Canny**: Gaussian smooth → gradient (mag+dir) → non-max suppression → double threshold + hysteresis.
- **LOG/DOG**: blob/edge detection; DOG ≈ LOG (efficient), used in SIFT scale-space.
- **Hough Transform**: edge pts → parameter space (ρ-θ) → peaks = lines.
- **Harris corner**: 2nd-moment matrix; corner = both eigenvalues large.
- **Hessian Affine**: Hessian matrix based, affine-invariant corner/blob detector.
- **Orientation Histogram / HOG**: local gradient direction histograms → object description (e.g. pedestrian detection).
- **SIFT**: DOG scale-space extrema → orientation assignment → gradient histogram descriptor; scale+rotation invariant.
- **SURF**: faster SIFT approx via integral images + box filters.
- **GLOH**: SIFT variant, log-polar grid, more distinctive/higher-dim.
- **Scale-space / pyramids**: multi-scale Gaussian smoothing+downsampling → scale-robust features.
- **Gabor filters**: frequency+orientation selective → texture analysis.
- **DWT**: multiresolution decomposition → freq+spatial feature extraction/compression.

---

## UNIT 4 — Image Segmentation
- **Region growing**: seed pixel → add similar neighbors until criteria fail.
- **Edge-based segmentation**: detect edges (gradient) → link into boundaries.
- **Graph-cut**: image as graph → min-cut separates fg/bg by edge weight similarity.
- **Mean-shift**: mode-seeking, shift pts to density peaks → clusters = segments.
- **MRFs**: pixel label depends on neighbor labels (probabilistic) → smooth/context-aware segmentation.
- **Texture segmentation**: segment by texture (Gabor responses/co-occurrence), not just intensity.
- **Object detection & recognition**: localize (bbox) + classify; builds on segmentation + features (HOG/SIFT) + classifier.

---

## Fastest Last-Look Priority
1. Radiance/Irradiance/BRDF, Ortho vs Perspective, Camera model+calibration (U1)
2. Histogram equalization steps, Snakes energy terms, Level sets vs snakes, Fourier descriptors (U2)
3. Canny steps, Harris, SIFT, Hough (U3)
4. Region growing vs edge-based, Graph-cut, Mean-shift, MRFs (U4)
