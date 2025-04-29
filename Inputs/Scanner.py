import cv2
import numpy as np
import os

def calibrate_colors():
    cap = cv2.VideoCapture(0)

    color_names = ['W', 'R', 'G', 'B', 'O', 'Y']  # White, Red, Green, Blue, Orange, Yellow
    calibrated_colors = {}

    print("\n🎯 Starting improved calibration...")
    print("Instructions:")
    print("- Hold each color (WHITE → RED → GREEN → BLUE → ORANGE → YELLOW) at center.")
    print("- Adjust till you see stable color.")
    print("- Press SPACE to confirm calibration.")
    print("- Press ESC to abort.")

    for color in color_names:
        while True:
            ret, frame = cap.read()
            frame = cv2.flip(frame, 1)

            h, w, _ = frame.shape
            cx, cy = w // 2, h // 2
            region_size = 20  # 40x40 region

            # Draw square at center
            cv2.rectangle(frame, (cx - region_size, cy - region_size),
                          (cx + region_size, cy + region_size), (0, 255, 0), 2)

            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            region = hsv[cy - region_size:cy + region_size, cx - region_size:cx + region_size]
            avg_hsv = np.mean(region.reshape(-1, 3), axis=0)

            bgr_color = cv2.cvtColor(np.uint8([[avg_hsv]]), cv2.COLOR_HSV2BGR)[0][0]
            bgr_color = tuple(int(c) for c in bgr_color)

            # Show preview of average color
            cv2.rectangle(frame, (10, 50), (110, 150), bgr_color, -1)
            cv2.putText(frame, f"Capturing: {color}", (10, 30),
                        cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

            cv2.imshow('Calibration', frame)
            key = cv2.waitKey(1)

            if key == ord(' '):
                calibrated_colors[color] = avg_hsv
                print(f"✅ Captured {color}: {avg_hsv}")
                break

            if key == 27:
                print("\n❌ Calibration Aborted.")
                cap.release()
                cv2.destroyAllWindows()
                return

    cap.release()
    cv2.destroyAllWindows()

    np.save('calibrated_colors.npy', calibrated_colors)
    print("\n✅ Calibration complete! Saved to 'calibrated_colors.npy'.")


def scan_cube():
    if not os.path.exists('calibrated_colors.npy'):
        print("❌ No calibration found! Please calibrate first (Option 1).")
        return

    calibrated_colors = np.load('calibrated_colors.npy', allow_pickle=True).item()

    face_order = ['U', 'L', 'F', 'R', 'B', 'D']  # UP, LEFT, FRONT, RIGHT, BACK, DOWN
    cube_state = {}

    cap = cv2.VideoCapture(0)
    face_idx = 0
    step = 80  # Bigger step for scanning

    def find_closest_color(hsv_pixel):
        min_dist = float('inf')
        closest_color = '?'
        for color, ref_hsv in calibrated_colors.items():
            dist = np.linalg.norm(hsv_pixel - ref_hsv)
            if dist < min_dist:
                min_dist = dist
                closest_color = color
        return closest_color

    print("\n🎯 Start scanning cube faces in order:")
    print("WHITE (U) → GREEN (L) → RED (F) → BLUE (R) → ORANGE (B) → YELLOW (D)")
    print("Press SPACE after aligning each face properly.\n")

    while face_idx < 6:
        ret, frame = cap.read()
        frame = cv2.flip(frame, 1)

        h, w, _ = frame.shape
        start_x, start_y = w // 2 - step * 1.5, h // 2 - step * 1.5

        # Draw 3x3 grid
        for i in range(4):
            cv2.line(frame, (int(start_x + i * step), int(start_y)),
                     (int(start_x + i * step), int(start_y + 3 * step)), (0, 255, 0), 2)
            cv2.line(frame, (int(start_x), int(start_y + i * step)),
                     (int(start_x + 3 * step), int(start_y + i * step)), (0, 255, 0), 2)

        cv2.putText(frame, f"Face: {face_order[face_idx]}", (10, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

        cv2.imshow('Scan Cube', frame)
        key = cv2.waitKey(1)

        if key == ord(' '):
            colors = []
            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            for row in range(3):
                for col in range(3):
                    x = int(start_x + col * step + step / 2)
                    y = int(start_y + row * step + step / 2)

                    region = hsv[y - 10:y + 10, x - 10:x + 10]
                    avg_color = np.mean(region.reshape(-1, 3), axis=0)

                    detected_color = find_closest_color(avg_color)
                    colors.append(detected_color)

            cube_state[face_order[face_idx]] = colors
            print(f"✅ Captured {face_order[face_idx]}: {colors}")
            face_idx += 1

        if key == 27:
            print("\n❌ Scanning aborted.")
            break

    cap.release()
    cv2.destroyAllWindows()

    if face_idx == 6:
        # Save cube state
        with open("cube_state.txt", "w") as f:
            for face in face_order:
                f.write(f"{face}: {' '.join(cube_state[face])}\n")

        print("\n✅ Cube state saved to 'cube_state.txt'. Ready to solve!")

if __name__ == "__main__":
    while True:
        print("\n========== Rubik's Cube Scanner ==========")
        print("1. Calibrate Colors (Improved)")
        print("2. Scan Cube")
        print("3. Exit")
        choice = input("Enter choice: ")

        if choice == '1':
            calibrate_colors()
        elif choice == '2':
            scan_cube()
        elif choice == '3':
            break
        else:
            print("Invalid choice. Try again.")
